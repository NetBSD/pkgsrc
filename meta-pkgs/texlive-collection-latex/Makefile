# $NetBSD: Makefile,v 1.20 2024/03/21 20:00:55 markd Exp $

DISTNAME=	collection-latex
PKGNAME=	texlive-${DISTNAME}-2024
CATEGORIES=	meta-pkgs
TEXLIVE_REV=	69131
MASTER_SITES=	# empty

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://www.tug.org/texlive/
COMMENT=	Basic LaTeX packages

DEPENDS+=	texlive-collection-basic>=2010:../../meta-pkgs/texlive-collection-basic

DEPENDS+=	tex-ae>=1.4:../../fonts/tex-ae
DEPENDS+=	tex-amscls>=2010.20248:../../print/tex-amscls
DEPENDS+=	tex-amsmath>=2.13nb1:../../print/tex-amsmath
DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-atveryend-[0-9]*:../../print/tex-atveryend
DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-babel>=3.8lnb2:../../print/tex-babel
DEPENDS+=	tex-babel-english>=3.3p:../../print/tex-babel-english
DEPENDS+=	tex-babelbib>=1.29:../../print/tex-babelbib
DEPENDS+=	tex-bigintcalc-[0-9]*:../../print/tex-bigintcalc
DEPENDS+=	tex-bitset-[0-9]*:../../print/tex-bitset
DEPENDS+=	tex-bookmark-[0-9]*:../../print/tex-bookmark
DEPENDS+=	tex-carlisle>=2010:../../print/tex-carlisle
DEPENDS+=	tex-colortbl>=0.1nb1:../../print/tex-colortbl
DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
DEPENDS+=	tex-etexcmds-[0-9]*:../../print/tex-etexcmds
DEPENDS+=	tex-fancyhdr>=3.1nb1:../../print/tex-fancyhdr
DEPENDS+=	tex-firstaid-[0-9]*:../../print/tex-firstaid
DEPENDS+=	tex-fix2col>=2016:../../print/tex-fix2col
DEPENDS+=	tex-geometry>=5.6:../../print/tex-geometry
DEPENDS+=	tex-gettitlestring-[0-9]*:../../print/tex-gettitlestring
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-graphics-cfg>=2016:../../print/tex-graphics-cfg
DEPENDS+=	tex-grfext-[0-9]*:../../print/tex-grfext
DEPENDS+=	tex-hopatch-[0-9]*:../../print/tex-hopatch
DEPENDS+=	tex-hycolor-[0-9]*:../../print/tex-hycolor
DEPENDS+=	tex-hyperref>=6.81pnb3:../../print/tex-hyperref
DEPENDS+=	tex-intcalc-[0-9]*:../../print/tex-intcalc
DEPENDS+=	tex-kvdefinekeys-[0-9]*:../../print/tex-kvdefinekeys
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-latex>=2010:../../print/tex-latex
DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin
DEPENDS+=	tex-latex-fonts>=2009:../../fonts/tex-latex-fonts
DEPENDS+=	tex-latex-lab-[0-9]*:../../print/tex-latex-lab
DEPENDS+=	tex-latexconfig>=2010.20663:../../print/tex-latexconfig
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-ltxmisc>=2010:../../print/tex-ltxmisc
DEPENDS+=	tex-mfnfss>=2009:../../print/tex-mfnfss
DEPENDS+=	tex-mptopdf>=2010:../../graphics/tex-mptopdf
DEPENDS+=	tex-natbib>=8.31b:../../print/tex-natbib
DEPENDS+=	tex-oberdiek>=2009nb2:../../print/tex-oberdiek
DEPENDS+=	tex-pagesel-[0-9]*:../../print/tex-pagesel
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-pslatex-[0-9]*:../../print/tex-pslatex
DEPENDS+=	tex-psnfss>=9.2anb1:../../fonts/tex-psnfss
DEPENDS+=	tex-pspicture>=2009:../../print/tex-pspicture
DEPENDS+=	tex-refcount-[0-9]*:../../print/tex-refcount
DEPENDS+=	tex-rerunfilecheck-[0-9]*:../../print/tex-rerunfilecheck
DEPENDS+=	tex-stringenc-[0-9]*:../../print/tex-stringenc
DEPENDS+=	tex-tools>=2009:../../print/tex-tools
DEPENDS+=	tex-uniquecounter-[0-9]*:../../print/tex-uniquecounter
DEPENDS+=	tex-url>=3.4:../../print/tex-url

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
