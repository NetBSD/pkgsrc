# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:17 rillig Exp $

DISTNAME=	carolmin-ps
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/carolmin-t1
COMMENT=	Adobe Type 1 format of Carolingian Minuscule fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	cmin.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
