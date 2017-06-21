# $NetBSD: Makefile,v 1.11 2017/06/21 07:24:07 markd Exp $

DISTNAME=	hyperref.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-6.85a
TEXLIVE_REV=	43547

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/hyperref
COMMENT=	Documentation for tex-hyperref
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb15

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
