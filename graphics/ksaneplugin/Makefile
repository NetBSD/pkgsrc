# $NetBSD: Makefile,v 1.5 2012/09/15 10:05:01 obache Exp $

DISTNAME=	ksaneplugin-${_KDE_VERSION}
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	SANE Plugin for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libksane/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
