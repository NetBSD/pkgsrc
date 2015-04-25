# $NetBSD: Makefile,v 1.16 2015/04/25 03:49:23 markd Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	36020

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
