# $NetBSD: Makefile,v 1.10 2002/12/24 06:10:18 wiz Exp $

DISTNAME=	kdenetwork-3.0.4
PKGREVISION=	3
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		yes
PTHREAD_OPTS+=		require

.include "../../converters/uulib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
