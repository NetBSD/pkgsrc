# $NetBSD: Makefile,v 1.5 2016/06/16 04:05:59 markd Exp $

DISTNAME=	babel.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.9r
TEXLIVE_REV=	40706

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-babel
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
