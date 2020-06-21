# $NetBSD: u-boot.mk,v 1.29 2020/06/21 10:06:53 wiz Exp $

.include "../../sysutils/u-boot/u-boot-version.mk"

PKGNAME?=	u-boot-${UBOOT_TARGET}-${UBOOT_VERSION:S/-/./}
DISTNAME?=	u-boot-${UBOOT_VERSION}
DISTINFO_FILE?=	${.CURDIR}/../../sysutils/u-boot/distinfo
CATEGORIES=	sysutils
EXTRACT_SUFX?=	.tar.bz2
PATCHDIR?=	${.CURDIR}/../../sysutils/u-boot/patches

HOMEPAGE?=	https://www.denx.de/wiki/U-Boot
MASTER_SITES?=	ftp://ftp.denx.de/pub/u-boot/

.if !empty(UBOOT_VERSION:M202[0-9].*)
PYTHON_VERSIONS_INCOMPATIBLE=	27
UBOOT_SWIG_VERSION=	3
.else
UBOOT_SWIG_VERSION=	3
PYTHON_VERSIONS_ACCEPTED?=	27
.endif

TOOL_DEPENDS+=	dtc>=1.4.2:../../sysutils/dtc
.if !empty(UBOOT_SWIG_VERSION:M3)
TOOL_DEPENDS+=	swig3>=swig-3.0.12:../../devel/swig3
.else
TOOL_DEPENDS+=	swig>=1.3:../../devel/swig
.endif

COMMENT=	Das U-Boot, the Universal Boot Loader (${UBOOT_CONFIG})
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison gmake gsed pkg-config gawk
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/tool.mk"

.if ${PYPKGPREFIX} == "py27"
ALL_ENV+= 		PYTHON2=${PYTHONBIN} PYTHONCONFIG=${PYTHONCONFIG}
.else
ALL_ENV+= 		PYTHON3=${PYTHONBIN} PYTHONCONFIG=${PYTHONCONFIG}
.endif
ALL_ENV+=		PYTHONLIBPATH=-L$(LOCALBASE)/lib

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
.if !empty(UBOOT_SWIG_VERSION:M3)
	${MKDIR} -p ${BUILDLINK_DIR}/bin
	${RM} -f ${BUILDLINK_DIR}/bin/swig3.0
	${LN} -s ${PREFIX}/bin/swig3.0 ${BUILDLINK_DIR}/bin/swig
.endif
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
