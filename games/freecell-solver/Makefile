# $NetBSD: Makefile,v 1.5 2022/06/28 11:33:56 wiz Exp $

DISTNAME=	freecell-solver-5.14.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	https://fc-solve.shlomifish.org/downloads/fc-solve/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fc-solve.shlomifish.org/
COMMENT=	Solves layouts of Freecell and similar variants of Card Solitaire
LICENSE=	mit

USE_TOOLS+=	gmake perl
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DFCS_WITH_TEST_SUITE=OFF
CMAKE_ARGS+=	-DBUILD_STATIC_LIBRARY=OFF

PYTHON_VERSIONS_INCOMPATIBLE=	27

BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
DEPENDS+=	${PYPKGPREFIX}-random2-[0-9]*:../../devel/py-random2
DEPENDS+=	${PYPKGPREFIX}-pysol_cards-[0-9]*:../../games/py-pysol_cards
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit

PKGCONFIG_OVERRIDE+=	libfreecell-solver.pc.in

REPLACE_PYTHON+=	board_gen/fc_solve_find_index_s2ints.py
REPLACE_PYTHON+=	board_gen/find-freecell-deal-index.py
REPLACE_PYTHON+=	board_gen/gen-multiple-pysol-layouts
REPLACE_PYTHON+=	board_gen/make_pysol_freecell_board.py
REPLACE_PYTHON+=	board_gen/transpose-freecell-board.py

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_MESSAGE.man=	Fix man dir.
SUBST_FILES.man=	cmake/Shlomif_Common.cmake
SUBST_SED.man=		-e 's:share/man:man:'

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
