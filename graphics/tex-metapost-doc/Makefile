# $NetBSD: Makefile,v 1.3 2013/12/03 22:44:48 minskim Exp $

DISTNAME=	metapost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.803
TEXLIVE_REV=	31860

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-metapost

CONFLICTS+=	teTeX-texmf<=3.0nb25

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
