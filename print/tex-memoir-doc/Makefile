# $NetBSD: Makefile,v 1.9 2016/06/16 04:06:12 markd Exp $

DISTNAME=	memoir.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.7f
TEXLIVE_REV=	41203

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/memoir
COMMENT=	Documentation for tex-memoir
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
