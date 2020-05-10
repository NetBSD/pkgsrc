# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:52 markd Exp $

DISTNAME=	pl
PKGNAME=	tex-${DISTNAME}-1.09
PKGREVISION=	1
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
