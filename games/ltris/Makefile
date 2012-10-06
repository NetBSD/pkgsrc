# $NetBSD: Makefile,v 1.26 2012/10/06 11:54:46 asau Exp $

DISTNAME=	ltris-1.0.18
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	SDL tetris clone

GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
