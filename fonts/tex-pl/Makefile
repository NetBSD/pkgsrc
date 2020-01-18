# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:48 rillig Exp $

DISTNAME=	pl
PKGNAME=	tex-${DISTNAME}-1.09
TEXLIVE_REV=	36012

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ctan.org/pkg/pl-mf
COMMENT=	Polish extension of Computer Modern fonts
LICENSE=	public-domain

TEX_MIXEDMAP_FILES+=	plother.map
TEX_MIXEDMAP_FILES+=	pltext.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
