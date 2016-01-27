# $NetBSD: Makefile,v 1.4 2016/01/27 10:00:26 markd Exp $

DISTNAME=	nomencl
PKGNAME=	tex-${DISTNAME}-3.1a
TEXLIVE_REV=	15878
DIST_SUBDIR=	${PKGBASE}-${TEXLIVE_REV}.2010

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Produce lists of symbols as in nomenclature
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb20

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
