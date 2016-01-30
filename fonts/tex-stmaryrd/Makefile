# $NetBSD: Makefile,v 1.6 2016/01/30 04:56:44 markd Exp $

DISTNAME=	stmaryrd
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	22027

MAINTAINER=	minskim@NetBSD.org
COMMENT=	St Mary Road symbols for theoretical computer science
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	stmaryrd.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
