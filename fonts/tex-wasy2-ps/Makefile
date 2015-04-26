# $NetBSD: Makefile,v 1.1 2015/04/26 03:15:12 markd Exp $

DISTNAME=	wasy2-ps
PKGNAME=	tex-${DISTNAME}-2014
CATEGORIES=	fonts
TEXLIVE_REV=	35830

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Type 1 versions of wasy2 fonts
LICENSE=	public-domain

DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy

TEX_MIXEDMAP_FILES+=	wasy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
