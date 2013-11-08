# $NetBSD: Makefile,v 1.2 2013/11/08 21:17:22 joerg Exp $

DISTNAME=	ucs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-20041710
TEXLIVE_REV=	17090

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ucs

REPLACE_PERL+=	doc/latex/ucs/*.pl

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/ucs/*.pl

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
