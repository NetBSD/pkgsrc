# $NetBSD: Makefile,v 1.18 2023/04/08 06:12:08 markd Exp $

DISTNAME=	biblatex
PKGNAME=	tex-${DISTNAME}-3.19
TEXLIVE_REV=	66403

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/biblatex
COMMENT=	Sophisticated Bibliographies in LaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-[0-9]*:../../print/tex-etex
DEPENDS+=	tex-bibtex-[0-9]*:../../print/tex-bibtex
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-logreq-[0-9]*:../../print/tex-logreq
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
DEPENDS+=	p5-biblatex-biber>=1.9:../../print/p5-biblatex-biber

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
