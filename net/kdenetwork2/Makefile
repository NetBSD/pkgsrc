# $NetBSD: Makefile,v 1.6 2001/11/13 21:25:54 jlam Exp $

DISTNAME=	kdenetwork-2.2.1
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES

.include "../../converters/uulib/buildlink.mk"
.include "../../databases/gdbm/buildlink.mk"
.include "../../devel/ptl2/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
