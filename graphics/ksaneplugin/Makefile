# $NetBSD: Makefile,v 1.31 2016/10/07 18:25:53 adam Exp $

DISTNAME=	ksaneplugin-15.12.0
PKGREVISION=	2
CATEGORIES=	graphics
COMMENT=	SANE Plugin for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/15.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libksane/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
