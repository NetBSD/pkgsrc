# $NetBSD: Makefile,v 1.23 2024/08/27 16:01:30 ryoon Exp $

DISTNAME=	minivmac-36.04.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
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
MVMTARGET=		nb64
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
MVMTARGET=		nbsd
.elif !empty(MACHINE_PLATFORM:MLinux-*-x86_64)
MVMTARGET=		lx64
.elif !empty(MACHINE_PLATFORM:MLinux-*-i386)
MVMTARGET=		lx86
.elif !empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
MVMTARGET=		mc64
.elif !empty(MACHINE_PLATFORM:MDarwin-*-i386)
MVMTARGET=		imch
.elif !empty(MACHINE_PLATFORM:MFreeBSD-*-x86_86)
MVMTARGET=		fb64
.elif !empty(MACHINE_PLATFORM:MFreeBSD-*-i386)
MVMTARGET=		fbsd
.elif !empty(MACHINE_PLATFORM:MOpenBSD-*-x86_64)
MVMTARGET=		ob64
.elif !empty(MACHINE_PLATFORM:MOpenBSD-*-i386)
MVMTARGET=		obsd
.elif !empty(MACHINE_PLATFORM:MDragonFly-*-x86_64)
MVMTARGET=		db64
.elif !empty(MACHINE_PLATFORM:MDragonFly-*-i386)
MVMTARGET=		dfbs
.elif !empty(MACHINE_PLATFORM:MSunOS-*-x86_64)
MVMTARGET=		oi64
.elif !empty(MACHINE_PLATFORM:MSunOS-*-i386)
MVMTARGET=		oind
.else
NOT_FOR_PLATFORM+=	${MACHINE_PLATFORM}
.endif

BUILD_TARGET=	minivmac

MODELS=		128K 512Ke Plus SE Classic SEFDHD II
BUILD_DIRS=	${MODELS}

INSTALLATION_DIRS+=	bin

do-configure:
	cd ${WRKSRC} && \
		${CC} setup/tool.c -o setup_t
.for d in ${MODELS}
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && \
		${LN} -sf ../src . && \
		../setup_t -t ${MVMTARGET} -m ${d} > ./setup.sh && \
		${SH} ./setup.sh
.endfor

do-install:
.for d in ${MODELS}
	echo $d
	${INSTALL_PROGRAM} ${WRKSRC}/${d}/minivmac \
		${DESTDIR}${PREFIX}/bin/minivmac-${d}
.endfor
	cd ${DESTDIR}${PREFIX}/bin && \
	${LN} -sf minivmac-Plus minivmac

.include "../../mk/oss.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
