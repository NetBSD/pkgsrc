# $NetBSD: Makefile,v 1.11 2002/09/14 18:33:06 wiz Exp $

DISTNAME=	kdenetwork-2.2.2
PKGREVISION=	2
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

PTHREAD_OPTS+=	require

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK_ONLY=	YES

.include "../../converters/uulib/buildlink.mk"
.include "../../databases/gdbm/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
