# $NetBSD: Makefile,v 1.8 2015/08/09 09:43:37 markd Exp $

DISTNAME=	memoir.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.7e
TEXLIVE_REV=	37809

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/memoir
COMMENT=	Documentation for tex-memoir
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
