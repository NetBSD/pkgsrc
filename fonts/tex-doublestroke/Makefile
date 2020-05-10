# $NetBSD: Makefile,v 1.4 2020/05/10 04:31:42 markd Exp $

DISTNAME=	doublestroke
PKGNAME=	tex-${DISTNAME}-1.111
PKGREVISION=	1
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/doublestroke
COMMENT=	Typeset mathematical double stroke symbols
#LICENSE=	other-free

TEX_MAP_FILES+=	dstroke.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
