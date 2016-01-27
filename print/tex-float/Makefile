# $NetBSD: Makefile,v 1.4 2016/01/27 10:42:26 markd Exp $

DISTNAME=	float
PKGNAME=	tex-${DISTNAME}-1.3d
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Improved interface for floating objects
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb19

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
