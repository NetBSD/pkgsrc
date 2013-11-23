# $NetBSD: Makefile,v 1.7 2013/11/23 00:04:04 minskim Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99d
TEXLIVE_REV=	29764

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-bibtex

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
