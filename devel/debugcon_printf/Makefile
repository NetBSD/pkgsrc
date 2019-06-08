# $NetBSD: Makefile,v 1.1 2019/06/08 23:52:09 kamil Exp $

DISTNAME=	debugcon_printf-20190609
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=krytarowski/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/krytarowski/debugcon_printf
COMMENT=	Bochs/Qemu debugcon printf() loadable kernel module for NetBSD
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64
OSVERSION_SPECIFIC=	YES

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PASSTHRU_DIRS+=	${BSDSRCDIR}/sys

MAKE_FLAGS+=	S=${BSDSRCDIR}/sys

BUILD_DEFS+=	BSDSRCDIR

.if !exists(${BSDSRCDIR}/sys)
PKG_FAIL_REASON+=	"BSDSRCDIR/sys specifies non-existing directory ${BSDSRCDIR}/sys"
.endif

.include "../../mk/compiler.mk"

KMOD=		${PKGBASE}.kmod
KMODULEDIR=	stand/${MACHINE}/${OS_VERSION}/modules/${PKGBASE}

INSTALLATION_DIRS+=	sbin		# auxiliary scripts
INSTALLATION_DIRS+=	${KMODULEDIR}

INSTALL_UNSTRIPPED=	yes # Kernel linker needs unstripped module

PLIST_SUBST+=	MACHINE=${MACHINE}

pre-configure:
	${CP} ${FILESDIR}/debugcon_printf-modunload  ${WRKSRC}
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@MACHINE@|${MACHINE}|g' \
		-e 's|@OS_VERSION@|${OS_VERSION}|g' \
		${FILESDIR}/${PKGBASE}-modload.in > ${WRKSRC}/${PKGBASE}-modload

do-install:
	${RUN} cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ${KMOD} ${DESTDIR}${PREFIX}/${KMODULEDIR}
.for file in debugcon_printf-modload debugcon_printf-modunload
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} ${file} ${DESTDIR}${PREFIX}/sbin
.endfor


.include "../../mk/bsd.pkg.mk"
