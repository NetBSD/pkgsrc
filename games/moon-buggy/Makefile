# $NetBSD: Makefile,v 1.7 2010/12/29 02:19:10 dholland Exp $
#

DISTNAME=		moon-buggy-1.0
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://seehuhn.de/data/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://seehuhn.de/media/programs/
COMMENT=		Game on the Moon

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

USE_TOOLS+=		makeinfo
INFO_FILES=		# PLIST

OWN_DIRS=		${VARBASE}/games/moon-buggy

.include "../../mk/bsd.pkg.mk"
