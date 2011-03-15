# $NetBSD: Makefile,v 1.1.1.1 2011/03/15 18:11:53 minskim Exp $

DISTNAME=	fontname.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	21489

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-fontname

CONFLICTS=	teTeX-texmf<=3.0nb29

INFO_FILES=	yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
