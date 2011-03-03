# $NetBSD: Makefile,v 1.3 2011/03/03 23:13:19 minskim Exp $

DISTNAME=	etex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.1.16381
TEXLIVE_REV=	21345

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-etex

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
