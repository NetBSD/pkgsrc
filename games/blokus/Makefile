# $NetBSD: Makefile,v 1.2 2007/02/02 22:12:28 rillig Exp $
#

DISTNAME=	blokus-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.saschahlusiak.de/blokus/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.saschahlusiak.de/blokus/
COMMENT=	Abstract strategy board game for two to four players

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
# XXX: For some reason, the other libraries are hidden when this is
# specified.
#LIBS.SunOS+=	-lGLU

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
