# $NetBSD: Makefile,v 1.5 2011/12/11 19:52:31 minskim Exp $

DISTNAME=	etex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.1.22198
TEXLIVE_REV=	22198

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-etex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
