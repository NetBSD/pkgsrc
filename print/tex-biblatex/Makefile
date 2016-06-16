# $NetBSD: Makefile,v 1.8 2016/06/16 04:06:00 markd Exp $

DISTNAME=	biblatex
PKGNAME=	tex-${DISTNAME}-3.4
TEXLIVE_REV=	41192

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/biblatex
COMMENT=	Bibliographies in LaTeX using BibTeX for sorting only
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-etoolbox>=2.1:../../devel/tex-etoolbox
DEPENDS+=	tex-logreq>=1.0:../../print/tex-logreq
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	p5-biblatex-biber>=1.9:../../print/p5-biblatex-biber

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
