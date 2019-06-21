# $NetBSD: Makefile,v 1.25 2019/06/21 16:02:16 mef Exp $

PKGNAME=	gnuradio-doxygen-${VERSION}
COMMENT=	Doxygen documentation of GNU Radio

.include	"../../ham/gnuradio-core/Makefile.common"
.include	"../../ham/gnuradio-core/Nocore.mk"

BUILD_DEPENDS+=	doxygen>=1.8.15:../../devel/doxygen
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx
BUILD_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

DEPENDS+=	web2c-[0-9]*:../../print/web2c
# in case those packages are already installed by other requirement..
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	tex-newunicodechar-[-0-9]*:../../print/tex-newunicodechar

CMAKE_ARGS+=	-DENABLE_DEFAULT=False
CMAKE_ARGS+=	-DENABLE_DOXYGEN=ON
CMAKE_ARGS+=	-DENABLE_SPHINX=ON

MAKE_JOBS_SAFE=	no

.include	"../../mk/bsd.pkg.mk"
