# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:56 markd Exp $

DISTNAME=	yfonts-t1
PKGNAME=	tex-${DISTNAME}-1.0
PKGREVISION=	1
TEXLIVE_REV=	36013

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/yfonts-t1
COMMENT=	Old German-style fonts, in Adobe type 1 format
#LICENSE=	otherfree

TEX_MAP_FILES+=	yfrak.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
