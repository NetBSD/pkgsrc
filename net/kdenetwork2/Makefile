# $NetBSD: Makefile,v 1.19 2004/01/23 21:50:47 jmmv Exp $

DISTNAME=	kdenetwork-2.2.2
PKGREVISION=	8
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde

USE_BUILDLINK2=	YES
PTHREAD_OPTS+=	require

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
