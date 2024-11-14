# $NetBSD: Makefile,v 1.6 2024/11/14 22:21:50 wiz Exp $

DISTNAME=	kcodecs-${KF6VER}
PKGREVISION=	4
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Collection of methods to manipulate strings using various encodings
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
