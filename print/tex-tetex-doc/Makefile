# $NetBSD: Makefile,v 1.14 2015/04/25 04:44:53 markd Exp $

DISTNAME=	tetex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.0.36067
TEXLIVE_REV=	36067

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tetex

CONFLICTS+=	teTeX-bin<=3.0nb42
CONFLICTS+=	texlive-tetex<=2011nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
