# $NetBSD: Makefile,v 1.14 2004/10/03 00:14:45 tv Exp $

DISTNAME=	kdetoys-2.2.2
PKGREVISION=	7
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK3=	YES

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
