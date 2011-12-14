# $NetBSD: Makefile,v 1.2 2011/12/14 20:27:11 minskim Exp $

DISTNAME=	xetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2011
TEXLIVE_REV=	24091

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-xetex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
