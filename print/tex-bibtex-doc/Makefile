# $NetBSD: Makefile,v 1.9 2017/09/06 16:49:31 wiz Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99d
PKGREVISION=	1
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bibtex
COMMENT=	Documentation for tex-bibtex
#LICENSE=	knuth

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
