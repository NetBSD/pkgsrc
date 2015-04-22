# $NetBSD: Makefile,v 1.4 2015/04/22 10:02:03 markd Exp $

DISTNAME=	babel.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.9l
TEXLIVE_REV=	35266

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-babel
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
