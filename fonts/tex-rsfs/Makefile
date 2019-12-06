# $NetBSD: Makefile,v 1.6 2019/12/06 19:32:24 markd Exp $

DISTNAME=	rsfs
PKGNAME=	tex-${DISTNAME}-2009
PKGREVISION=	1
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Ralph Smith's Formal Script font

TEX_MIXEDMAP_FILES+=	rsfs.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
