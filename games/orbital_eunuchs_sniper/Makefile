# $NetBSD: Makefile,v 1.2 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=		orbital_eunuchs_sniper-1.29
PKGREVISION=	1
CATEGORIES=		games
MASTER_SITES=		http://filesingularity.timedoctor.org/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://icculus.org/oes/
COMMENT=		Overhead shooting game

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-games-dir=${PREFIX}/libexec

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/orbital_eunuchs_sniper
	${INSTALL_DATA} ${WRKSRC}/README \
		${PREFIX}/share/doc/orbital_eunuchs_sniper
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${PREFIX}/share/doc/orbital_eunuchs_sniper

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
