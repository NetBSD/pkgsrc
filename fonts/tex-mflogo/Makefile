# $NetBSD: Makefile,v 1.5 2011/11/06 08:43:31 minskim Exp $

DISTNAME=	mflogo
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	17487
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support for MetaFont logo fonts

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	mflogo.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
