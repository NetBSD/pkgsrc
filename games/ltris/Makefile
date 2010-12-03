# $NetBSD: Makefile,v 1.22 2010/12/03 18:49:22 drochner Exp $

DISTNAME=	ltris-1.0.15
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	SDL tetris clone

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
