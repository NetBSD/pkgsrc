# $NetBSD: Makefile,v 1.18 2017/06/21 13:25:33 markd Exp $

DISTNAME=	tetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.0.44331
TEXLIVE_REV=	44331

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tetex

CONFLICTS+=	teTeX-bin<=3.0nb42
CONFLICTS+=	texlive-tetex<=2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
