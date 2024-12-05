# $NetBSD: Makefile,v 1.29 2024/12/05 09:53:09 markd Exp $

DISTNAME=	extra-cmake-modules-6.8.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extra modules and scripts for CMake
LICENSE=	modified-bsd

USE_LANGUAGES=	c++

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
