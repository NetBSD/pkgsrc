# $NetBSD: Makefile,v 1.5 2016/01/30 04:56:43 markd Exp $

DISTNAME=	lm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.004
TEXLIVE_REV=	28119

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-lm
LICENSE=	gfsl

CONFLICTS+=	teTeX-texmf<=3.0nb16

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
