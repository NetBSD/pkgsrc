# $NetBSD: Makefile,v 1.2 2019/12/06 19:32:19 markd Exp $

DISTNAME=	pl
PKGNAME=	tex-${DISTNAME}-1.09
TEXLIVE_REV=	36012

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ctan.org/pkg/pl-mf
COMMENT=	Polish extension of Computer Modern fonts
LICENSE=	public-domain

TEX_MIXEDMAP_FILES+=	plother.map
TEX_MIXEDMAP_FILES+=	pltext.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
