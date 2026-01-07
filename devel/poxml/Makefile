# $NetBSD: Makefile,v 1.59 2026/01/07 08:46:44 wiz Exp $

DISTNAME=	poxml-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/
COMMENT=	Translates DocBook XML files using gettext po files
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
