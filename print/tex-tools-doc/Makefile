# $NetBSD: Makefile,v 1.6 2015/04/25 05:13:59 markd Exp $

DISTNAME=	tools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2014
TEXLIVE_REV=	35577

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tools
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
