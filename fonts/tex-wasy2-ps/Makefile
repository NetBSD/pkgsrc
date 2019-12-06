# $NetBSD: Makefile,v 1.2 2019/12/06 19:32:32 markd Exp $

DISTNAME=	wasy2-ps
PKGNAME=	tex-${DISTNAME}-2014
CATEGORIES=	fonts
TEXLIVE_REV=	35830

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Type 1 versions of wasy2 fonts
LICENSE=	public-domain

DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy

TEX_MIXEDMAP_FILES+=	wasy.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
