# $NetBSD: Makefile,v 1.5 2002/08/28 07:15:37 skrll Exp $

DISTNAME=	kdenetwork-3.0.3
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	yes
PTHREAD_OPTS+=		require

.include "../../converters/uulib/buildlink.mk"
.include "../../databases/gdbm/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
