# $NetBSD: Makefile,v 1.4 2016/01/27 10:13:21 markd Exp $

DISTNAME=	microtype.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.5a
TEXLIVE_REV=	30755

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-microtype
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
