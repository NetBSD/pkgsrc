# $NetBSD: Makefile,v 1.13 2020/01/18 23:31:19 rillig Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2018.49028
CATEGORIES=	fonts
TEXLIVE_REV=	49028

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cm
COMMENT=	Computer Modern fonts
#LICENSE=	knuth

TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
