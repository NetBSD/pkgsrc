# $NetBSD: Makefile,v 1.8 2016/06/16 04:06:17 markd Exp $

DISTNAME=	tools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2016
TEXLIVE_REV=	40934

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tools
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
