# $NetBSD: Makefile,v 1.7 2020/05/10 04:31:56 markd Exp $

DISTNAME=	xypic
PKGNAME=	tex-${DISTNAME}-3.8.9
PKGREVISION=	1
TEXLIVE_REV=	31859

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Flexible diagramming macros
LICENSE=	gnu-gpl-v2

TEX_MIXEDMAP_FILES+=	xypic.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
