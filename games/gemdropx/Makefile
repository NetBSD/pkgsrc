# $NetBSD: Makefile,v 1.19 2008/06/20 01:09:20 joerg Exp $
#

DISTNAME=	gemdropx-0.9
PKGREVISION=	5
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/gemdropx/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/gemdropx/
COMMENT=	Color puzzle game for X11 similar to Gem Drop

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			DATA_PREFIX=${DESTDIR}${PREFIX}/share/gemdropx

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
