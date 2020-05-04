# $NetBSD: Makefile,v 1.23 2020/05/04 04:24:07 ryoon Exp $

DISTNAME=	hyperref
PKGNAME=	tex-${DISTNAME}-7.00d
TEXLIVE_REV=	54841

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hyperref
COMMENT=	Extensive support for hypertext in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-bitset-[0-9]*:../../print/tex-bitset
DEPENDS+=	tex-etexcmds-[0-9]*:../../print/tex-etexcmds
DEPENDS+=	tex-gettitlestring-[0-9]*:../../print/tex-gettitlestring
DEPENDS+=	tex-graphics>=1.0onb1:../../print/tex-graphics
DEPENDS+=	tex-hycolor-[0-9]*:../../print/tex-hycolor
DEPENDS+=	tex-intcalc-[0-9]*:../../print/tex-intcalc
DEPENDS+=	tex-kvdefinekeys-[0-9]*:../../print/tex-kvdefinekeys
DEPENDS+=	tex-kvsetkeys-[0-9]*:../../print/tex-kvsetkeys
DEPENDS+=	tex-latex-bin>=2009nb1:../../print/tex-latex-bin
DEPENDS+=	tex-letltxmacro-[0-9]*:../../print/tex-letltxmacro
DEPENDS+=	tex-ltxcmds-[0-9]*:../../print/tex-ltxcmds
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek
DEPENDS+=	tex-pdfescape-[0-9]*:../../print/tex-pdfescape
DEPENDS+=	tex-refcount-[0-9]*:../../print/tex-refcount
DEPENDS+=	tex-rerunfilecheck-[0-9]*:../../print/tex-rerunfilecheck
DEPENDS+=	tex-stringenc-[0-9]*:../../print/tex-stringenc
DEPENDS+=	tex-url>=3.2:../../print/tex-url
DEPENDS+=	tex-zapfding-[0-9]*:../../fonts/tex-zapfding

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
