# $NetBSD: Makefile,v 1.20 2022/02/05 03:25:56 ryoon Exp $

DISTNAME=	haxm-7.7.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/intel/haxm/
COMMENT=	Intel Hardware Accelerated Execution Manager
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64
OSVERSION_SPECIFIC=	YES
USE_BSD_MAKEFILE=	YES

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

BUILD_DIRS=	platforms/netbsd

MKPIE_SUPPORTED=	no
.include "../../mk/bsd.prefs.mk"

BUILDLINK_PASSTHRU_DIRS+=	${BSDSRCDIR}/sys

MAKE_FLAGS+=	S=${BSDSRCDIR}/sys

BUILD_DEFS+=	BSDSRCDIR

.if !exists(${BSDSRCDIR}/sys)
PKG_FAIL_REASON+=	"BSDSRCDIR/sys specifies non-existing directory ${BSDSRCDIR}/sys"
.endif

.include "../../mk/compiler.mk"

MAKE_FLAGS+=	NOCLANGERROR=1
MAKE_FLAGS+=	NOGCCERROR=1

KMOD=		haxm.kmod
KMODULEDIR=	stand/${MACHINE}/${OS_VERSION}/modules/haxm

INSTALLATION_DIRS+=	sbin		# auxiliary scripts
INSTALLATION_DIRS+=	${KMODULEDIR}

INSTALL_UNSTRIPPED=	yes # Kernel linker needs unstripped module

PLIST_SUBST+=	MACHINE=${MACHINE}

pre-configure:
.for file in haxm-mknod haxm-modunload
	${CP} ${FILESDIR}/${file} ${WRKSRC}
.endfor
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@MACHINE@|${MACHINE}|g' \
		-e 's|@OS_VERSION@|${OS_VERSION}|g' \
		${FILESDIR}/haxm-modload.in > ${WRKSRC}/haxm-modload

do-install:
	${RUN} cd ${WRKSRC}/platforms/netbsd && \
		${INSTALL_PROGRAM} ${KMOD} ${DESTDIR}${PREFIX}/${KMODULEDIR}
.for file in haxm-modload haxm-modunload haxm-mknod
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} ${file} ${DESTDIR}${PREFIX}/sbin
.endfor


.include "../../mk/bsd.pkg.mk"
