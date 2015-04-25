# $NetBSD: Makefile,v 1.5 2015/04/25 03:39:07 markd Exp $

DISTNAME=	context.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	35839

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-context

CONFLICTS+=	teTeX-texmf<=3.0nb29
CONFLICTS+=	texlive-tetex<=2009

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
