# $NetBSD: Makefile,v 1.2 2015/08/02 12:21:43 markd Exp $

DISTNAME=	minitoc.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-61
TEXLIVE_REV=	37852

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/minitoc
COMMENT=	Documentation for tex-minitoc
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<3.0nb29

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
