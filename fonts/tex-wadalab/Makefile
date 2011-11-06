# $NetBSD: Makefile,v 1.2 2011/11/06 08:43:30 minskim Exp $

DISTNAME=	wadalab
PKGNAME=	tex-${DISTNAME}-2011
PKGREVISION=	1
TEXLIVE_REV=	22576

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Wadalab (Japanese) font packages

TEX_MAP_FILES+=	dgj.map
TEX_MAP_FILES+=	dmj.map
TEX_MAP_FILES+=	mc2j.map
TEX_MAP_FILES+=	mcj.map
TEX_MAP_FILES+=	mr2j.map
TEX_MAP_FILES+=	mrj.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
