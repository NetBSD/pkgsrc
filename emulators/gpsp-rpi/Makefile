# $NetBSD: Makefile,v 1.2 2015/04/25 14:20:45 tnn Exp $

DISTNAME=	gpsp-rpi-20150205
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/jmcneill/rpi/
EXTRACT_SUFX=	.zip

MAINTAINER=	port-arm@NetBSD.org
HOMEPAGE=	https://github.com/DPRCZ/gpsp
COMMENT=	Gameboy Advance emulator (Raspberry Pi version)
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	NetBSD-*-*arm*

WRKSRC=		${WRKDIR}/gpsp-master
USE_TOOLS+=	gmake

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries.
SUBST_FILES.vc=		raspberrypi/Makefile
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
BUILDLINK_TRANSFORM+=	rm:-ldl

INSTALLATION_DIRS=	bin

do-build:
	cd ${WRKSRC}/raspberrypi && gmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/raspberrypi/gpsp \
	    ${DESTDIR}${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
