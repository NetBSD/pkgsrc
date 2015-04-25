# $NetBSD: Makefile,v 1.3 2015/04/25 05:20:08 markd Exp $

DISTNAME=	ucs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.2
TEXLIVE_REV=	35853

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ucs
LICENSE=	lppl-1.3c

REPLACE_PERL+=	doc/latex/ucs/*.pl
REPLACE_PERL+=	doc/latex/ucs/unsupported/u2ps

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/ucs/*.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
