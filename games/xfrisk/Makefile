# $NetBSD: Makefile,v 1.4 2003/09/30 08:26:51 xtraeme Exp $
#

DISTNAME=	xfrisk-1.2
PKGREVISION=	1
WRKSRC=		${WRKDIR}/XFrisk
CATEGORIES=	games
MASTER_SITES=	http://morphy.iki.fi/xfrisk/files/

MAINTAINER=	sketch@rd.bbc.co.uk
HOMEPAGE=	http://morphy.iki.fi/xfrisk/
COMMENT=	X11 version of the classic Risk board game

USE_BUILDLINK2=	yes
USE_GMAKE=	yes
USE_X11=	yes

RESTRICTED=	"Possible trademark infringement"
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=      LIBS="-lsocket -lnsl"
.endif

# xfrisk doesn't work with standard Xaw.
XAW_TYPE?=	3d

.if ${XAW_TYPE} == standard
XAW_TYPE=3d
.endif

.include "../../mk/xaw.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
