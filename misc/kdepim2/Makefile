# $NetBSD: Makefile,v 1.8 2002/03/13 17:37:26 fredb Exp $

DISTNAME=	kdepim-2.2.2
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES
LTCONFIG_OVERRIDE+=	${WRKSRC}/libical/ltconfig

.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
