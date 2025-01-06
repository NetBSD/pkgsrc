# $NetBSD: Makefile,v 1.23 2025/01/06 21:49:13 ktnb Exp $
#

DISTNAME=	gemdropx-0.9
PKGREVISION=	7
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/gemdropx/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/gemdropx/
COMMENT=	Color puzzle game for X11 similar to Gem Drop

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			DATA_PREFIX=${DESTDIR}${PREFIX}/share/gemdropx

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
