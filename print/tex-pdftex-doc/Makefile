# $NetBSD: Makefile,v 1.11 2012/10/16 20:03:24 minskim Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.40.11pl27932
TEXLIVE_REV=	27932

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf/doc/man/man1/pdftex.1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
