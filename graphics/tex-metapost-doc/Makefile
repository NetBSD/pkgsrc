# $NetBSD: Makefile,v 1.5 2016/01/30 04:05:50 markd Exp $

DISTNAME=	metapost.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.803pl34194
TEXLIVE_REV=	34194

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-metapost
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb25

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/doc/man

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
