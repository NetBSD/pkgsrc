# $NetBSD: Makefile,v 1.4 2002/08/01 05:48:12 jlam Exp $

DISTNAME=	kdegames-3.0.2
CATEGORIES=	games
COMMENT=	Games for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	YES
PTHREAD_OPTS+=		require

.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
