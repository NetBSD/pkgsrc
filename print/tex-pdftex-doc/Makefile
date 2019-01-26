# $NetBSD: Makefile,v 1.20 2019/01/26 08:39:32 markd Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2018
TEXLIVE_REV=	48806

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pdftex
COMMENT=	Documentation for tex-pdftex
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/pdftex.1

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/doc/pdftex/manual/syntaxform.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
