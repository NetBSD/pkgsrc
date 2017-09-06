# $NetBSD: Makefile,v 1.6 2017/09/06 16:49:41 wiz Exp $

DISTNAME=	ms
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	29849

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Various LaTeX packages by Martin Schroeder
LICENSE=	lppl-1.3c

DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
