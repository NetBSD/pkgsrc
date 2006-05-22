# $NetBSD: Makefile,v 1.3 2006/05/22 20:01:18 joerg Exp $
#

DISTNAME=		moon-buggy-1.0
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://seehuhn.de/data/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://seehuhn.de/data/
COMMENT=		Game on the Moon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

INFO_FILES=		# PLIST

OWN_DIRS=		${VARBASE}/games/moon-buggy

.include "../../mk/bsd.pkg.mk"
