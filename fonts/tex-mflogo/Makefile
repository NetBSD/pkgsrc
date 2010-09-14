# $NetBSD: Makefile,v 1.4 2010/09/14 20:50:11 minskim Exp $

DISTNAME=	mflogo
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	17487
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX support for MetaFont logo fonts

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	mflogo.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
