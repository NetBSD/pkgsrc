# $NetBSD: Makefile,v 1.8 2010/12/29 19:08:39 wiz Exp $
#

DISTNAME=		moon-buggy-1.0
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://seehuhn.de/data/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://seehuhn.de/media/programs/
COMMENT=		Game on the Moon
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

USE_TOOLS+=		makeinfo
INFO_FILES=		YES

OWN_DIRS=		${VARBASE}/games/moon-buggy
BUILD_DEFS=		VARBASE

.include "../../mk/bsd.pkg.mk"
