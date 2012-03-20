# $NetBSD: Makefile,v 1.1.1.1 2012/03/20 05:25:38 markd Exp $

DISTNAME=	kcalc-${_KDE_VERSION}
CATEGORIES=	math
COMMENT=	KDE scientific calculator

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/gmp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
