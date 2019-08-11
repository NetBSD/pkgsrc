# $NetBSD: Makefile,v 1.14 2019/08/11 11:40:46 markd Exp $

DISTNAME=	l3kernel
PKGNAME=	tex-${DISTNAME}-2019.51745
TEXLIVE_REV=	51745

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/l3kernel
COMMENT=	LaTeX3 programming conventions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-booktabs-[0-9]*:../../print/tex-booktabs
DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-csquotes-[0-9]*:../../print/tex-csquotes
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-fancyvrb-[0-9]*:../../print/tex-fancyvrb
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-l3backend-[0-9]*:../../devel/tex-l3backend
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-underscore-[0-9]*:../../print/tex-underscore

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
