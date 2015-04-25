# $NetBSD: Makefile,v 1.7 2015/04/25 03:43:42 markd Exp $

DISTNAME=	dvipdfmx.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	35703

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvipdfmx

TEXLIVE_IGNORE_PATTERNS+=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
