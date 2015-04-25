# $NetBSD: Makefile,v 1.18 2015/04/25 14:20:25 tnn Exp $
#

.include "../../audio/xmms/Makefile.common"

PKGNAME=	${DISTNAME:S/xmms/xmms-esound/}
PKGREVISION=	4
CATEGORIES+=	gnome

COMMENT=	XMMS plugin to output sound through the esound daemon

CONFLICTS+=	xmms<=1.2.7nb8

BUILDLINK_API_DEPENDS.xmms+=	xmms>=1.2.7nb9

BUILD_DIRS=	Output/esd
INSTALL_DIRS=	Output/esd

USE_TOOLS+=	pkg-config

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
