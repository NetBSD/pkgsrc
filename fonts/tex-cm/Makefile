# $NetBSD: Makefile,v 1.12 2019/12/06 19:29:43 markd Exp $

DISTNAME=	cm
PKGNAME=	tex-${DISTNAME}-2018.49028
CATEGORIES=	fonts
TEXLIVE_REV=	49028

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/cm
COMMENT=	Computer Modern fonts
#LICENSE=	knuth

TEX_MIXEDMAP_FILES+=	cmtext-bsr-interpolated.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
