# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:11 jmmv Exp $
#

DISTNAME=	xfrisk-1.2
WRKSRC=		${WRKDIR}/XFrisk
CATEGORIES=	games
MASTER_SITES=	http://morphy.iki.fi/xfrisk/files/

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://morphy.iki.fi/xfrisk/
COMMENT=	X11 version of the classic Risk board game

USE_GMAKE=	yes
USE_X11=	yes

RESTRICTED=	"Possible trademark infringement"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=      LIBS="-lsocket -lnsl"
.endif

.include "../../mk/bsd.pkg.mk"
