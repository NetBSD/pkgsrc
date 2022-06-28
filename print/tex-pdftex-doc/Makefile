# $NetBSD: Makefile,v 1.27 2022/06/28 11:35:32 wiz Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2020
PKGREVISION=	3
TEXLIVE_REV=	54227

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdftex
COMMENT=	Documentation for tex-pdftex
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/pdftex.1

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/doc/pdftex/manual/syntaxform.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
