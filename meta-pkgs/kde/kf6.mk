# $NetBSD: kf6.mk,v 1.1 2024/03/19 11:21:15 markd Exp $
# used by x11/kf6-kwindowsystem/Makefile

KF6VER=		6.0.0
CATEGORIES+=	kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${KF6VER:R}/}
EXTRACT_SUFX=	.tar.xz

TOOL_DEPENDS+= extra-cmake-modules>=${KF6VER}:../../devel/extra-cmake-modules
TOOLS_DEPENDS.cmake= cmake>=3.0:../../devel/cmake

CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true
.include "../../meta-pkgs/kde/Makefile.common"
