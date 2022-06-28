# $NetBSD: Makefile,v 1.3 2022/06/28 11:33:55 wiz Exp $

DISTNAME=	black-hole-solver-1.10.1
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://fc-solve.shlomifish.org/downloads/fc-solve/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.shlomifish.org/open-source/projects/black-hole-solitaire-solver/
COMMENT=	Solvers and statistics for various solitaire and related card patience games
LICENSE=	mit

USE_TOOLS+=	gmake perl
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DBUILD_STATIC_LIBRARY=OFF

PYTHON_FOR_BUILD_ONLY=		tool
PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny

PKGCONFIG_OVERRIDE+=	libblack-hole-solver.pc.in

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix man dir.
SUBST_FILES.man=	cmake/Shlomif_Common.cmake
SUBST_SED.man=		-e 's:share/man:man:'

.include "../../devel/rinutils/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
