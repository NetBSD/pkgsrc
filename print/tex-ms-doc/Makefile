# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:13 minskim Exp $

DISTNAME=	ms.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009.16596
TEXLIVE_REV=	16596
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ms

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
