# $NetBSD: Makefile,v 1.6 2022/09/01 05:47:16 markd Exp $

DISTNAME=	ucs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.3
TEXLIVE_REV=	64114

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ucs
COMMENT=	Documentation for tex-ucs
LICENSE=	lppl-1.3c

REPLACE_PERL+=	doc/latex/ucs/*.pl
REPLACE_PERL+=	doc/latex/ucs/unsupported/u2ps

CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/latex/ucs/*.pl \
				share/texmf-dist/doc/latex/ucs/unsupported/u2ps

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
