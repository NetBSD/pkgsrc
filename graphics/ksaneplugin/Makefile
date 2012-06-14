# $NetBSD: Makefile,v 1.2 2012/06/14 07:44:29 sbd Exp $

DISTNAME=	ksaneplugin-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	graphics
COMMENT=	SANE Plugin for KDE

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libksane/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
