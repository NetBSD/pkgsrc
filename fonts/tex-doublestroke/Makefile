# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:24 rillig Exp $

DISTNAME=	doublestroke
PKGNAME=	tex-${DISTNAME}-1.111
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/doublestroke
COMMENT=	Typeset mathematical double stroke symbols
#LICENSE=	other-free

TEX_MAP_FILES+=	dstroke.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
