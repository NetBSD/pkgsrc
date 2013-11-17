# $NetBSD: Makefile,v 1.15 2013/11/17 16:53:18 minskim Exp $

DISTNAME=	dvips
PKGNAME=	tex-${DISTNAME}-2013
TEXLIVE_REV=	32132

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Files for a DVI to PostScript driver
LICENSE=	gnu-gpl-v2

CONFLICTS+=	teTeX-texmf<=3.0nb15
CONFLICTS+=	tex-bin-dvipsk<=2008.12898

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/dvips/base

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
