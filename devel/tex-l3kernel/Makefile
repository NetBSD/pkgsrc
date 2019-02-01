# $NetBSD: Makefile,v 1.10 2019/02/01 22:52:04 markd Exp $

DISTNAME=	l3kernel
PKGNAME=	tex-${DISTNAME}-2018.49853
TEXLIVE_REV=	49853

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/l3kernel
COMMENT=	LaTeX3 programming conventions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-csquotes-[0-9]*:../../print/tex-csquotes
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-underscore-[0-9]*:../../print/tex-underscore

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
