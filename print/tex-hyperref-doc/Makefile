# $NetBSD: Makefile,v 1.10 2016/08/07 09:09:38 markd Exp $

DISTNAME=	hyperref.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-6.83q
TEXLIVE_REV=	41539

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/hyperref
COMMENT=	Documentation for tex-hyperref
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb15

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
