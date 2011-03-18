# $NetBSD: Makefile,v 1.1.1.1 2011/03/18 23:27:28 minskim Exp $

DISTNAME=	jadetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.13
TEXLIVE_REV=	18835

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-jadetex

CONFLICTS=	tex-jadetex<=3.13nb7

TEX_TEXMF_DIRS=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
