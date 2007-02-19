# $NetBSD: Makefile,v 1.4 2007/02/19 09:47:14 rillig Exp $
#

DISTNAME=	blokus-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.saschahlusiak.de/blokus/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.saschahlusiak.de/blokus/
COMMENT=	Abstract strategy board game for two to four players

RESTRICTED=		Redistribution prohibited
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
# XXX: For some reason, the other libraries are hidden when this is
# specified.
#LIBS.SunOS+=	-lGLU

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
