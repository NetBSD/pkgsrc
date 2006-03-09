# $NetBSD: Makefile,v 1.8 2006/03/09 14:50:31 ghen Exp $
#

DISTNAME=		orbital_eunuchs_sniper-1.29
PKGREVISION=		5
CATEGORIES=		games
MASTER_SITES=		http://filesingularity.timedoctor.org/

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://icculus.org/oes/
COMMENT=		Overhead shooting game

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-games-dir=${PREFIX}/libexec

REPLACE_INTERPRETER+=	bash
_REPLACE.bash.old=	.*/bin/bash
_REPLACE.bash.new=	${SH:Q}
_REPLACE_FILES.bash=	src/snipe2d.in

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
