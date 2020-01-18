# $NetBSD: Makefile,v 1.11 2020/01/18 23:33:42 rillig Exp $

DISTNAME=	bibtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.99d
PKGREVISION=	1
TEXLIVE_REV=	33736

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bibtex
COMMENT=	Documentation for tex-bibtex
#LICENSE=	knuth

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
