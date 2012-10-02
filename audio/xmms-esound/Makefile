# $NetBSD: Makefile,v 1.16 2012/10/02 23:48:15 asau Exp $
#

.include "../../audio/xmms/Makefile.common"

PKGNAME=	${DISTNAME:S/xmms/xmms-esound/}
PKGREVISION=	3
CATEGORIES+=	gnome

COMMENT=	XMMS plugin to output sound through the esound daemon

CONFLICTS+=	xmms<=1.2.7nb8

BUILDLINK_API_DEPENDS.xmms+=	xmms>=1.2.7nb9

BUILD_DIRS=	${WRKSRC}/Output/esd
INSTALL_DIRS=	${WRKSRC}/Output/esd

USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
