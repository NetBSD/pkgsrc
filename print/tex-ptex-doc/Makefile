# $NetBSD: Makefile,v 1.1.1.1 2011/01/23 01:27:00 minskim Exp $

DISTNAME=	ptex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.1.9
TEXLIVE_REV=	21070

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ptex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
