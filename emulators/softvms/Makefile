# $NetBSD: Makefile,v 1.3 2020/01/26 17:31:09 rillig Exp $

DISTNAME=	softvms
PKGNAME=	softvms-1.10
CATEGORIES=	emulators
MASTER_SITES=	http://mc.pp.se/dc/files/
MASTER_SITES+=	https://travispaul.me/distfiles/

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://mc.pp.se/dc/sw.html
COMMENT=	Emulator capable of running some Sega VMS games
LICENSE=	mit

WRKSRC=			${WRKDIR}/vms
GNU_CONFIGURE=		yes
DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin

BUILD_TARGET=		vms

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vms ${DESTDIR}${PREFIX}/bin/vms

.include "../../x11/libX11/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
