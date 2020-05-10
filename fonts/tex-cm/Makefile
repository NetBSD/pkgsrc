# $NetBSD: Makefile,v 1.14 2020/05/10 04:31:41 markd Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2018.49028
PKGREVISION=	1
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
