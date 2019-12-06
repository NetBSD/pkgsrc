# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:37 markd Exp $

DISTNAME=	ucs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.2
TEXLIVE_REV=	35853

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ucs
LICENSE=	lppl-1.3c

REPLACE_PERL+=	doc/latex/ucs/*.pl
REPLACE_PERL+=	doc/latex/ucs/unsupported/u2ps

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/ucs/*.pl \
				share/texmf-dist/doc/latex/ucs/unsupported/u2ps

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
