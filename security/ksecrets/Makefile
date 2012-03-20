# $NetBSD: Makefile,v 1.1 2012/03/20 05:55:34 markd Exp $

DISTNAME=	ksecrets-${_KDE_VERSION}
CATEGORIES=	security
COMMENT=	KDE secrets service

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../security/qca2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
