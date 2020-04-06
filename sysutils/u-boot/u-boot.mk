# $NetBSD: u-boot.mk,v 1.23 2020/04/06 14:54:54 tnn Exp $

.include "../../sysutils/u-boot/u-boot-version.mk"

PKGNAME?=	u-boot-${UBOOT_TARGET}-${UBOOT_VERSION:S/-/./}
DISTNAME?=	u-boot-${UBOOT_VERSION}
DISTINFO_FILE?=	${.CURDIR}/../../sysutils/u-boot/distinfo
CATEGORIES=	sysutils
EXTRACT_SUFX?=	.tar.bz2
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches

HOMEPAGE?=	https://www.denx.de/wiki/U-Boot
MASTER_SITES?=	ftp://ftp.denx.de/pub/u-boot/

TOOL_DEPENDS+=	dtc>=1.4.2:../../sysutils/dtc
TOOL_DEPENDS+=	swig>=1.3:../../devel/swig

COMMENT=	Das U-Boot, the Universal Boot Loader (${UBOOT_CONFIG})
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake gsed pkg-config gawk
PYTHON_FOR_BUILD_ONLY=	yes
ALL_ENV+= 		PYTHON2=${PYTHONBIN} PYTHONCONFIG=${PYTHONCONFIG}
ALL_ENV+=		PYTHONLIBPATH=-L$(LOCALBASE)/lib
PYTHON_VERSIONS_ACCEPTED=	27

SUBST_CLASSES+=		pythonpath
SUBST_STAGE.pythonpath=	pre-configure
SUBST_FILES.pythonpath=	tools/dtoc/dtoc
SUBST_SED.pythonpath=	-e "s|/usr/bin/python|${PYTHONBIN}|g"

REPLACE_INTERPRETER+=	python2
REPLACE.python2.old=	python2
REPLACE.python2.new=	${PYTHONBIN}
REPLACE_FILES.python2=	scripts/fill_scrapyard.py \
			tools/binman/binman \
			tools/binman/binman.py \
			tools/dtoc/dtoc.py \
			tools/genboardscfg.py \
			tools/moveconfig.py

.if defined(PKGREVISION) && !empty(PKGREVISION) && (${PKGREVISION} != "0")
UBOOT_ENV+=	UBOOT_PKGREVISION=nb${PKGREVISION}
.endif

MAKE_ENV+=	${UBOOT_ENV}

post-patch:
.for opt in ${UBOOT_OPTIONS}
	@echo "=> Adding ${opt} to configs/${UBOOT_CONFIG}"
	@echo ${opt} >> ${WRKSRC}/configs/${UBOOT_CONFIG}
.endfor

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${UBOOT_CONFIG}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${_MAKE_JOBS}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}
.for bin in ${UBOOT_BIN}
	${INSTALL_DATA} ${WRKSRC}/${bin} \
	    ${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}
.endfor
.if defined(UBOOT_INSTALLBOOT_PLIST)
	${INSTALL_DATA} ${.CURDIR}/files/${UBOOT_INSTALLBOOT_PLIST} \
	    ${DESTDIR}${PREFIX}/share/u-boot/${UBOOT_TARGET}/installboot.plist
.endif

.include "../../lang/python/tool.mk"
