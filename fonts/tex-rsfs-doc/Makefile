# $NetBSD: Makefile,v 1.3 2010/09/14 00:24:39 minskim Exp $

DISTNAME=	rsfs.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2009
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-rsfs

CONFLICTS+=	teTeX-texmf<=3.0nb15


.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
