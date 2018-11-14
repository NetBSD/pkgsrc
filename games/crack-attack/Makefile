# $NetBSD: Makefile,v 1.48 2018/11/14 22:21:28 kleink Exp $

DISTNAME=	crack-attack-1.1.14
PKGREVISION=	34
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/crack-attack/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://savannah.nongnu.org/projects/crack-attack
COMMENT=	Tetris Attack inspired game

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-sound=yes
CONFIGURE_ARGS+=	--disable-binreloc
USE_LANGUAGES=		c c++03
USE_TOOLS+=		pkg-config

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.jpg	\
	    ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
