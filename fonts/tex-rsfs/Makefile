# $NetBSD: Makefile,v 1.4 2011/11/06 08:43:32 minskim Exp $

DISTNAME=	rsfs
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Ralph Smith's Formal Script font

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	rsfs.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
