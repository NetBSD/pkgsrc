# $NetBSD: Makefile,v 1.35 2026/08/17 05:40:26 wiz Exp $
#
# changelog:
# https://kde.org/announcements/frameworks/6/6.nn.0/

DISTNAME=	extra-cmake-modules-6.29.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extra modules and scripts for CMake
LICENSE=	modified-bsd

USE_LANGUAGES=	c++

#TOOLS_DEPEND+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

CMAKE_CONFIGURE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_HTML_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MAN_DOCS=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_QTHELP_DOCS=OFF

CHECK_INTERPRETER_SKIP+=	share/ECM/kde-modules/kde-git-commit-hooks/clang-format.sh
CHECK_INTERPRETER_SKIP+=	share/ECM/kde-modules/kde-git-commit-hooks/json-schema.py
CHECK_INTERPRETER_SKIP+=	share/ECM/kde-modules/kde-git-commit-hooks/pre-commit.in

pre-configure:
	${FIND} ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
