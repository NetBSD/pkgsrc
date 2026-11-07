# $NetBSD: Makefile,v 1.20 2026/11/07 19:12:02 wiz Exp $

DISTNAME=	kcodecs-${KF6VER}
PKGREVISION=	3
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Collection of methods to manipulate strings using various encodings
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

#USE_CXX_FEATURES+=	c++23    # <format> c++20 feature but not in gcc12

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
