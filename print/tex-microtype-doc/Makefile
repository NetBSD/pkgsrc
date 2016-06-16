# $NetBSD: Makefile,v 1.5 2016/06/16 04:06:12 markd Exp $

DISTNAME=	microtype.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.6a
TEXLIVE_REV=	41127

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-microtype
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
