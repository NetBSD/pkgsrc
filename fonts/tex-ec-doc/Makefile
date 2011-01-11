# $NetBSD: Makefile,v 1.2 2011/01/11 17:00:01 minskim Exp $

DISTNAME=	ec.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.0
TEXLIVE_REV=	15878
DIST_SUBDIR=	tex-${DISTNAME:S/.doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-ec

CONFLICTS+=	teTeX-texmf<=3.0nb24

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
