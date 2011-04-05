# $NetBSD: Makefile,v 1.4 2011/04/05 17:19:24 minskim Exp $

DISTNAME=	etex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.1.16381
TEXLIVE_REV=	21566

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-etex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
