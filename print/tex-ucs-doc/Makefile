# $NetBSD: Makefile,v 1.7 2024/02/17 01:40:11 markd Exp $

DISTNAME=	ucs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.4
TEXLIVE_REV=	68759

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
