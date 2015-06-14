# $NetBSD: Makefile,v 1.15 2015/06/14 12:50:06 markd Exp $

DISTNAME=	tetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.0.37485
TEXLIVE_REV=	37485

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tetex

CONFLICTS+=	teTeX-bin<=3.0nb42
CONFLICTS+=	texlive-tetex<=2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
