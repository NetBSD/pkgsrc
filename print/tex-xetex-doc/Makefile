# $NetBSD: Makefile,v 1.1.1.1 2011/01/21 17:56:10 minskim Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2010
TEXLIVE_REV=	18937

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-xetex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
