# $NetBSD: Makefile,v 1.10 2012/10/06 11:54:47 asau Exp $
#

DISTNAME=		moon-buggy-1.0
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://seehuhn.de/data/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://seehuhn.de/media/programs/
COMMENT=		Game on the Moon
LICENSE=		gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

USE_TOOLS+=		makeinfo
INFO_FILES=		YES

OWN_DIRS=		${VARBASE}/games/moon-buggy
BUILD_DEFS=		VARBASE

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
