# $NetBSD: Makefile,v 1.7 2002/09/20 08:16:50 jlam Exp $

DISTNAME=	kdetoys-2.2.2
PKGREVISION=	1
CATEGORIES=	games
COMMENT=	Toys for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=	YES

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
