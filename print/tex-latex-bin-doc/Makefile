# $NetBSD: Makefile,v 1.11 2026/04/03 06:03:44 markd Exp $

DISTNAME=	latex-bin.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2026
TEXLIVE_REV=	78282

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-latex-bin

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/latex.1
TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/pdflatex.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
