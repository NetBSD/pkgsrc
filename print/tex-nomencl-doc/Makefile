# $NetBSD: Makefile,v 1.3 2010/10/01 16:35:32 minskim Exp $

DISTNAME=	nomencl.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.1a
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-nomencl

CONFLICTS+=	teTeX-texmf<=3.0nb20

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
