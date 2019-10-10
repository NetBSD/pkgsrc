# $NetBSD: Makefile,v 1.21 2019/10/10 13:54:17 ryoon Exp $

DISTNAME=	minivmac-36.04.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	emulators
MASTER_SITES=	https://www.gryphel.com/d/minivmac/minivmac-${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gryphel.com/c/minivmac/
COMMENT=	Miniature Macintosh emulator
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/minivmac

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting X11BASE
SUBST_FILES.prefix+=	setup/WRBGCFLS.i
SUBST_VARS.prefix+=	X11BASE COMPILER_RPATH_FLAG

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
MVMTARGET=	nb64
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
MVMTARGET=	nbsd
.elif !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
MVMTARGET=	lx64
.elif !empty(MACHINE_PLATFORM:MLinux-*-i386)
MVMTARGET=	lx86
.elif !empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
MVMTARGET=	mc64
.elif !empty(MACHINE_PLATFORM:MDarwin-*-i386)
MVMTARGET=	imch
.elif !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_86)
MVMTARGET=	fb64
.elif !empty(MACHINE_PLATFORM:MFreeBSD-*-i386)
MVMTARGET=	fbsd
.elif !empty(MACHINE_PLATFORM:MOpenBSD-*-x86_64)
MVMTARGET=	ob64
.elif !empty(MACHINE_PLATFORM:MOpenBSD-*-i386)
MVMTARGET=	obsd
.elif !empty(MACHINE_PLATFORM:MDragonFly-*-x86_64)
MVMTARGET=	db64
.elif !empty(MACHINE_PLATFORM:MDragonFly-*-i386)
MVMTARGET=	dfbs
.elif !empty(MACHINE_PLATFORM:MSunOS-*-x86_64)
MVMTARGET=	oi64
.elif !empty(MACHINE_PLATFORM:MSunOS-*-i386)
MVMTARGET=	oind
.else
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

BUILD_TARGET=	minivmac

INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC} && \
		${CC} setup/tool.c -o setup_t && \
		./setup_t -t ${MVMTARGET} > ./setup.sh && \
		${SH} ./setup.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/minivmac ${DESTDIR}${PREFIX}/bin

.include "../../mk/oss.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
