# $NetBSD: Makefile,v 1.8 2011/02/02 18:30:20 minskim Exp $

DISTNAME=	pdftex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.40.11
PKGREVISION=	1
TEXLIVE_REV=	21248

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-pdftex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
