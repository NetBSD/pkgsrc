# $NetBSD: Makefile,v 1.8 2006/02/05 23:08:17 joerg Exp $
#

.include "../../audio/xmms/Makefile.common"

PKGNAME=	${DISTNAME:S/xmms/xmms-esound/}
PKGREVISION=	3
CATEGORIES+=	gnome

COMMENT=	XMMS plugin to output sound through the esound daemon

CONFLICTS+=	xmms<=1.2.7nb8

BUILDLINK_DEPENDS.xmms+=	xmms>=1.2.7nb9

BUILD_DIRS=	${WRKSRC}/Output/esd
INSTALL_DIRS=	${WRKSRC}/Output/esd

.include "../../audio/esound/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
