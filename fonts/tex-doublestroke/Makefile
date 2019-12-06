# $NetBSD: Makefile,v 1.2 2019/12/06 19:29:50 markd Exp $

DISTNAME=	doublestroke
PKGNAME=	tex-${DISTNAME}-1.111
TEXLIVE_REV=	15878

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/doublestroke
COMMENT=	Typeset mathematical double stroke symbols
#LICENSE=	other-free

TEX_MAP_FILES+=	dstroke.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
