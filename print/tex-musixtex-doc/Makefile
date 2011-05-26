# $NetBSD: Makefile,v 1.1.1.1 2011/05/26 23:51:16 minskim Exp $

DISTNAME=	musixtex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.15
TEXLIVE_REV=	22568

MAINTAINER=	dgriffi@cs.csubak.edu
COMMENT=	Documentation for tex-musixtex
LICENSE=	gnu-gpl-v2

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
