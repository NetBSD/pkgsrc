# $NetBSD: Makefile,v 1.4 2001/11/13 21:17:16 jlam Exp $

DISTNAME=	kdegames-2.2.1
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
