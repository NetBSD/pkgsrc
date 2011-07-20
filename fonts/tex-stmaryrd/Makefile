# $NetBSD: Makefile,v 1.4 2011/07/20 02:25:55 minskim Exp $

DISTNAME=	stmaryrd
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	22027

MAINTAINER=	minskim@NetBSD.org
COMMENT=	St Mary Road symbols for theoretical computer science

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	stmaryrd.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
