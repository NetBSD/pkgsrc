# $NetBSD: Makefile,v 1.3 2010/09/14 00:18:08 minskim Exp $

DISTNAME=	algorithms.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009
TEXLIVE_REV=	15878
DIST_SUBDIRS=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-algorithms
LICENSE=	gnu-lgpl-v2.1

CONFLICTS+=	teTeX-texmf<=3.0nb19

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
