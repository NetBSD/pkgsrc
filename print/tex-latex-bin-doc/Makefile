# $NetBSD: Makefile,v 1.9 2024/04/22 12:06:41 markd Exp $

DISTNAME=	latex-bin.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2024
PKGREVISION=	1
TEXLIVE_REV=	70501

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-latex-bin

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/latex.1
TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man/man1/pdflatex.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
