# $NetBSD: Makefile,v 1.2 2010/09/14 00:18:14 minskim Exp $

DISTNAME=	pslatex
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	16416
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use PostScript fonts by default

CONFLICTS+=	teTeX-texmf<=3.0nb24

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
