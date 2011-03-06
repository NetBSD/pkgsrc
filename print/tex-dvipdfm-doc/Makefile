# $NetBSD: Makefile,v 1.6 2011/03/06 22:30:16 minskim Exp $

DISTNAME=	dvipdfm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-0.13.2d
PKGREVISION=	2
TEXLIVE_REV=	21369

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-dvipdfm

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
