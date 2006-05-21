# $NetBSD: Makefile,v 1.2 2006/05/21 15:44:55 rillig Exp $
#

DISTNAME=		moon-buggy-1.0
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://seehuhn.de/data/

MAINTAINER=		rillig@NetBSD.org
HOMEPAGE=		http://seehuhn.de/data/
COMMENT=		Game on the Moon

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

OWN_DIRS=		${VARBASE}/games/moon-buggy

.include "../../mk/bsd.pkg.mk"
