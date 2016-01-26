# $NetBSD: Makefile,v 1.4 2016/01/26 11:25:35 markd Exp $

DISTNAME=	sectsty
PKGNAME=	tex-${DISTNAME}-2.0.2
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Control sectional headers
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb17

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
