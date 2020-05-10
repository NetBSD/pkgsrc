# $NetBSD: Makefile,v 1.4 2020/05/10 04:32:06 markd Exp $

DISTNAME=	omega
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	33046

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/omega
COMMENT=	A wide-character-set extension of TeX
LICENSE=	gnu-gpl-v2

TEX_MAP_FILES+=	omega.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
