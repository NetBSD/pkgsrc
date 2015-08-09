# $NetBSD: Makefile,v 1.16 2015/08/09 11:04:54 markd Exp $

DISTNAME=	tetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.0.38001
TEXLIVE_REV=	38001

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tetex

CONFLICTS+=	teTeX-bin<=3.0nb42
CONFLICTS+=	texlive-tetex<=2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
