# $NetBSD: Makefile,v 1.17 2022/09/01 03:25:54 markd Exp $

DISTNAME=	biblatex
PKGNAME=	tex-${DISTNAME}-3.18b
TEXLIVE_REV=	63878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/biblatex
COMMENT=	Sophisticated Bibliographies in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-etoolbox>=2.1:../../devel/tex-etoolbox
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-logreq>=1.0:../../print/tex-logreq
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	p5-biblatex-biber>=1.9:../../print/p5-biblatex-biber

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
