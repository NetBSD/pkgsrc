# $NetBSD: Makefile,v 1.5 2020/05/10 04:31:47 markd Exp $

DISTNAME=	lato
PKGNAME=	tex-${DISTNAME}-3.3
PKGREVISION=	1
TEXLIVE_REV=	51462

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lato
COMMENT=	Lato font family and LaTeX support
LICENSE=	ofl-v1.1 AND lppl-1.3c

TEX_MAP_FILES+=	lato.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
