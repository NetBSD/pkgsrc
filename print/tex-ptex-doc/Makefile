# $NetBSD: Makefile,v 1.2 2011/02/07 19:59:44 minskim Exp $

DISTNAME=	ptex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.1.9
TEXLIVE_REV=	21270

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ptex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
