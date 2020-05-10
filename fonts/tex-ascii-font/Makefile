# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:37 markd Exp $

DISTNAME=	ascii-font
PKGNAME=	tex-${DISTNAME}-2.0
PKGREVISION=	1
TEXLIVE_REV=	29989

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ascii-font
COMMENT=	Use the ASCII "font" in LaTeX
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	ascii.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
