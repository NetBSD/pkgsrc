# $NetBSD: Makefile,v 1.7 2015/06/14 12:50:06 markd Exp $

DISTNAME=	tools.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2015
TEXLIVE_REV=	36834

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-tools
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
