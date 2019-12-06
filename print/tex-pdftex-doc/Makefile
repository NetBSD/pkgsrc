# $NetBSD: Makefile,v 1.22 2019/12/06 20:23:01 markd Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2018
PKGREVISION=	1
TEXLIVE_REV=	48806

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/pdftex
COMMENT=	Documentation for tex-pdftex
LICENSE=	gnu-gpl-v2

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man/man1/pdftex.1

USE_TOOLS+=	perl:run
REPLACE_PERL+=	texmf-dist/doc/pdftex/manual/syntaxform.pl

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
