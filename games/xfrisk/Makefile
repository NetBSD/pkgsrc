# $NetBSD: Makefile,v 1.1.1.1 2002/02/27 21:38:46 agc Exp $
#

DISTNAME=	xfrisk-1.2
CATEGORIES=	games
MASTER_SITES=	http://morphy.iki.fi/xfrisk/files/

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://morphy.iki.fi/xfrisk/
COMMENT=	X11 version of the classic Risk board game

WRKSRC=		${WRKDIR}/XFrisk

USE_GMAKE=	yes
USE_X11=	yes

RESTRICTED=	"Possible trademark infringement"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

.include "../../mk/bsd.pkg.mk"
