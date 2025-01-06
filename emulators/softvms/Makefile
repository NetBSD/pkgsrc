# $NetBSD: Makefile,v 1.5 2025/01/06 21:49:07 ktnb Exp $

DISTNAME=	softvms
PKGNAME=	softvms-1.10
PKGREVISION=	2
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
