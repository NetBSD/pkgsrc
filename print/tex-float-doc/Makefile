# $NetBSD: Makefile,v 1.5 2019/12/06 20:21:25 markd Exp $

DISTNAME=	float.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.3d
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE:S/-doc//}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Documentation for tex-float
LICENSE=	lppl-1.3c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
