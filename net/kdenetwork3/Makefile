# $NetBSD: Makefile,v 1.3 2002/07/17 07:54:09 skrll Exp $

DISTNAME=	kdenetwork-3.0.2
CATEGORIES=	net
COMMENT=	Network modules for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	yes
USE_PTHREAD=		native pth-syscall

.include "../../converters/uulib/buildlink.mk"
.include "../../databases/gdbm/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
