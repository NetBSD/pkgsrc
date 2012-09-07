# $NetBSD: Makefile,v 1.27 2012/09/07 19:16:35 adam Exp $

DISTNAME=	crack-attack-1.1.14
PKGREVISION=	15
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/crack-attack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/crack-attack
COMMENT=	Tetris Attack inspired game

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-sound=yes
CONFIGURE_ARGS+=	--disable-binreloc
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.jpg	\
	    ${DESTDIR}${PREFIX}/share/doc/html/${PKGBASE}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
