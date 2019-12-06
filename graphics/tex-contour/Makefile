# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:20 markd Exp $

DISTNAME=	contour
PKGNAME=	tex-${DISTNAME}-2.14
TEXLIVE_REV=	18950

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/contour
COMMENT=	Print a coloured contour around text
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
