# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:39 markd Exp $

DISTNAME=	caladea
PKGNAME=	tex-${DISTNAME}-2014.08.17
PKGREVISION=	1
TEXLIVE_REV=	34991

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/caladea
COMMENT=	Support for the Caladea family of fonts
LICENSE=	apache-2.0

TEX_MAP_FILES+=	caladea.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
