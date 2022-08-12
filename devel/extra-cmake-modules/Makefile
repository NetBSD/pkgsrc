# $NetBSD: Makefile,v 1.21 2022/08/12 08:26:31 adam Exp $

DISTNAME=	extra-cmake-modules-5.93.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extra modules and scripts for CMake
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	# none
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_KDE_build

CMAKE_ARGS+=	-DBUILD_TESTING=OFF
CMAKE_ARGS+=	-DBUILD_HTML_DOCS=OFF
CMAKE_ARGS+=	-DBUILD_MAN_DOCS=OFF
CMAKE_ARGS+=	-DBUILD_QTHELP_DOCS=OFF

CHECK_INTERPRETER_SKIP+=	share/ECM/kde-modules/kde-git-commit-hooks/clang-format.sh
CHECK_INTERPRETER_SKIP+=	share/ECM/kde-modules/kde-git-commit-hooks/pre-commit.in

pre-configure:
	${MKDIR} ${WRKSRC}/_KDE_build
	${FIND} ${WRKSRC} -name \*.orig -exec rm {} \;

.include "../../mk/bsd.pkg.mk"
