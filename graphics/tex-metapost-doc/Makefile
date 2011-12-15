# $NetBSD: Makefile,v 1.2 2011/12/15 22:34:40 minskim Exp $

DISTNAME=	metapost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.212
TEXLIVE_REV=	23089

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-metapost

CONFLICTS+=	teTeX-texmf<=3.0nb25

TEX_TEXMF_DIRS+=		${PREFIX}/share/texmf-dist
TEXLIVE_IGNORE_PATTERNS=	texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
