# $NetBSD: Makefile,v 1.4 2010/09/14 00:18:17 minskim Exp $

DISTNAME=	listings.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.4
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-listings

CONFLICTS+=	teTeX-texmf<=3.0nb20

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
