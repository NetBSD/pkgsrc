# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:24 joerg Exp $
#

DISTNAME=	xfrisk-1.2
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.tuxick.net/xfrisk/files/

MAINTAINER=	sketch@NetBSD.org
HOMEPAGE=	http://www.tuxick.net/xfrisk/
COMMENT=	X11 version of the classic Risk board game

WRKSRC=		${WRKDIR}/XFrisk
USE_TOOLS+=	gmake

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

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
