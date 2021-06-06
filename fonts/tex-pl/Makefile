# $NetBSD: Makefile,v 1.5 2021/06/06 22:03:46 markd Exp $

DISTNAME=	pl
PKGNAME=	tex-${DISTNAME}-1.09a
TEXLIVE_REV=	58661

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pl-mf
COMMENT=	Polish extension of Computer Modern fonts
LICENSE=	public-domain

TEX_MIXEDMAP_FILES+=	plother.map
TEX_MIXEDMAP_FILES+=	pltext.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
