# $NetBSD: Makefile,v 1.12 2026/04/03 05:43:13 markd Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99e
TEXLIVE_REV=	77830

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bibtex
COMMENT=	Documentation for tex-bibtex
#LICENSE=	knuth

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
