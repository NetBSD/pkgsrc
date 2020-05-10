# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:40 markd Exp $

DISTNAME=	carolmin-ps
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/carolmin-t1
COMMENT=	Adobe Type 1 format of Carolingian Minuscule fonts
LICENSE=	lppl-1.3c

TEX_MAP_FILES+=	cmin.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
