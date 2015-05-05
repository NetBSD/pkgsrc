# $NetBSD: Makefile,v 1.8 2015/05/05 16:41:25 wiz Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99d
PKGREVISION=	1
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bibtex
COMMENT=	Documentation for tex-bibtex
#LICENSE=	knuth

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
