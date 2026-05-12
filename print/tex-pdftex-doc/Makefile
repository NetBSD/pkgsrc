# $NetBSD: Makefile,v 1.31 2026/05/12 13:25:37 mef Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2026
TEXLIVE_REV=	78401

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdftex
COMMENT=	Documentation for tex-pdftex
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/doc/pdftex/manual/syntaxform.pl
REPLACE_BASH+=	texmf-dist/doc/pdftex/tests/38-interword-space-at-font-switch/postpdf.sh

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/pdftex/tests/38-interword-space-at-font-switch/compare_pdfs.rb

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
