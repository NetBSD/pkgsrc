# $NetBSD: Makefile,v 1.11 2004/01/23 21:50:45 jmmv Exp $

DISTNAME=	kdegames-2.2.2
PKGREVISION=	5
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=	YES

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
