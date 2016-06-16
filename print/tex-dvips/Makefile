# $NetBSD: Makefile,v 1.19 2016/06/16 04:06:03 markd Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	41149

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/dvips
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
