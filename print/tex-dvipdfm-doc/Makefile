# $NetBSD: Makefile,v 1.2 2010/10/28 00:14:50 minskim Exp $

DISTNAME=	dvipdfm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.13.2d
TEXLIVE_REV=	19724

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/shrae/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
