# $NetBSD: Makefile,v 1.22 2004/10/03 00:17:53 tv Exp $

DISTNAME=	kdenetwork-2.2.2
PKGREVISION=	10
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK3=	YES
PTHREAD_OPTS+=	require

.include "../../converters/uulib/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
