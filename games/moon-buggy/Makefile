# $NetBSD: Makefile,v 1.6 2010/01/29 23:39:48 joerg Exp $
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

INFO_FILES=		# PLIST

OWN_DIRS=		${VARBASE}/games/moon-buggy

.include "../../mk/bsd.pkg.mk"
