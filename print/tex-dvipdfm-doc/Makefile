# $NetBSD: Makefile,v 1.3 2011/01/22 20:56:29 minskim Exp $

DISTNAME=	dvipdfm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.13.2d
TEXLIVE_REV=	21040

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/shrae/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
