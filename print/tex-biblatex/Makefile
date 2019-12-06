# $NetBSD: Makefile,v 1.12 2019/12/06 20:18:59 markd Exp $

DISTNAME=	biblatex
PKGNAME=	tex-${DISTNAME}-3.12
TEXLIVE_REV=	49069

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/biblatex
COMMENT=	Sophisticated Bibliographies in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-etoolbox>=2.1:../../devel/tex-etoolbox
DEPENDS+=	tex-logreq>=1.0:../../print/tex-logreq
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	p5-biblatex-biber>=1.9:../../print/p5-biblatex-biber

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
