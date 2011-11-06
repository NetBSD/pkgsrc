# $NetBSD: Makefile,v 1.5 2011/11/06 08:43:32 minskim Exp $

DISTNAME=	stmaryrd
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	22027

MAINTAINER=	minskim@NetBSD.org
COMMENT=	St Mary Road symbols for theoretical computer science

CONFLICTS+=	teTeX-texmf<=3.0nb15

TEX_MIXEDMAP_FILES+=	stmaryrd.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
