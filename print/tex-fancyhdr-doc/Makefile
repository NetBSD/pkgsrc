# $NetBSD: Makefile,v 1.4 2016/01/27 10:42:25 markd Exp $

DISTNAME=	fancyhdr.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-3.1
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-fancyhdr
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
