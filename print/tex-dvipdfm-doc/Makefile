# $NetBSD: Makefile,v 1.5 2011/02/02 18:24:47 minskim Exp $

DISTNAME=	dvipdfm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.13.2d
PKGREVISION=	1
TEXLIVE_REV=	21248

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
