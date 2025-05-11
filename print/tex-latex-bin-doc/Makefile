# $NetBSD: Makefile,v 1.10 2025/05/11 03:50:57 markd Exp $

DISTNAME=	latex-bin.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2025
TEXLIVE_REV=	73848

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-latex-bin

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/latex.1
TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/pdflatex.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
