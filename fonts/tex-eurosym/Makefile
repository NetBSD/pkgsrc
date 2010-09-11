# $NetBSD: Makefile,v 1.2 2010/09/11 02:16:39 minskim Exp $

DISTNAME=	eurosym
PKGNAME=	tex-${DISTNAME}-1.4
CATEGORIES=	fonts
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}-20090910
TEXLIVE_REV=	17265

MAINTAINER=	nico@orgrim.net
COMMENT=	MetaFont and macros for Euro sign

CONFLICTS+=	teTeX-texmf<=3.0nb27

TEX_MIXEDMAP_FILES+=	eurosym.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
