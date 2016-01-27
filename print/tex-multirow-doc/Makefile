# $NetBSD: Makefile,v 1.4 2016/01/27 10:13:21 markd Exp $

DISTNAME=	multirow.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.6
PKGREVISION=	1
TEXLIVE_REV=	17256
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-multirow
LICENSE=	lppl-1.0

CONFLICTS+=	teTeX-texmf<=3.0nb16

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
