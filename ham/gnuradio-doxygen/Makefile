# $NetBSD: Makefile,v 1.62 2023/01/13 23:02:51 wiz Exp $

PKGNAME=	gnuradio-doxygen-${VERSION}
PKGREVISION=	3
COMMENT=	Doxygen documentation of GNU Radio

.include "../../ham/gnuradio-core/Makefile.common"
.include "../../ham/gnuradio-core/Nocore.mk"

BUILD_DEPENDS+=	doxygen>=1.9.5:../../devel/doxygen
BUILD_DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

DEPENDS+=	web2c-[0-9]*:../../print/web2c
# in case those packages are already installed by other requirement..
DEPENDS+=	texlive-collection-latex-[0-9]*:../../meta-pkgs/texlive-collection-latex
DEPENDS+=	tex-newunicodechar-[0-9]*:../../print/tex-newunicodechar

CMAKE_ARGS+=	-DENABLE_DEFAULT=OFF
CMAKE_ARGS+=	-DENABLE_DOXYGEN=ON

#MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
