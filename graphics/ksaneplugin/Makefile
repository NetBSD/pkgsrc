# $NetBSD: Makefile,v 1.40 2018/12/13 19:52:01 adam Exp $

DISTNAME=	ksaneplugin-16.12.0
PKGREVISION=	7
CATEGORIES=	graphics
COMMENT=	SANE Plugin for KDE
MASTER_SITES=	${MASTER_SITE_KDE:=applications/16.12.0/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../graphics/libksane/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
