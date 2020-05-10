# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:37 markd Exp $

DISTNAME=	arphic
PKGNAME=	tex-${DISTNAME}-2.11
PKGREVISION=	2
TEXLIVE_REV=	15878

MAINTAINER=	rxg@NetBSD.org
COMMENT=	Arphic (Chinese) font packages
LICENSE=	arphic-public

TEX_MAP_FILES+=	bkaiu.map
TEX_MAP_FILES+=	bsmiu.map
TEX_MAP_FILES+=	gbsnu.map
TEX_MAP_FILES+=	gkaiu.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
