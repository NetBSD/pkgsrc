# $NetBSD: Makefile,v 1.3 2016/01/27 09:46:18 markd Exp $

DISTNAME=	pslatex
PKGNAME=	tex-${DISTNAME}-2009
TEXLIVE_REV=	16416
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Use PostScript fonts by default
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb24

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
