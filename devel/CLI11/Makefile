# $NetBSD: Makefile,v 1.1 2025/01/13 18:37:07 gdt Exp $

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	CLI11-2.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=CLIUtils/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/CLIUtils/CLI11/
COMMENT=	Command line parser for C++11
LICENSE=	modified-bsd

# \todo Hoist this somehow to mk/git.
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++11

PKGCONFIG_OVERRIDE+=	cmake/CLI11.pc.in
PKGCONFIG_OVERRIDE+=	cmake/CLI11precompiled.pc.in

.include "../../devel/cmake/build.mk"
CMAKE_CONFIGURE_ARGS+=	-DCLI11_BUILD_EXAMPLES=off

# \todo 'make test' builds tests but does not run them.

# catch2 should be test depends, but upstream incorrectly tries to
# download it, even if one has not asked to run tests.
.include "../../devel/catch2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

