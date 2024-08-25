# $NetBSD: Makefile,v 1.28 2024/08/25 06:18:33 wiz Exp $

DISTNAME=	extra-cmake-modules-6.2.0
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE:=frameworks/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Extra modules and scripts for CMake
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

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
