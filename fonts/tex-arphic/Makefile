# $NetBSD: Makefile,v 1.3 2017/07/27 11:07:41 markd Exp $

DISTNAME=	arphic
PKGNAME=	tex-${DISTNAME}-2.11
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	rxg@NetBSD.org
COMMENT=	Arphic (Chinese) font packages
LICENSE=	arphic-public

TEX_MAP_FILES+=	bkaiu.map
TEX_MAP_FILES+=	bsmiu.map
TEX_MAP_FILES+=	gbsnu.map
TEX_MAP_FILES+=	gkaiu.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
