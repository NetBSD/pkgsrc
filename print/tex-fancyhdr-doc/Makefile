# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:11 minskim Exp $

DISTNAME=	fancyhdr.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.1
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-fancyhdr

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
