# $NetBSD: Makefile,v 1.1 2022/08/19 19:49:04 wiz Exp $

DISTNAME=	arabic-book
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	59594

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/arabic-book
COMMENT=	Arabic book class
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-caption-[0-9]*:../../print/tex-caption
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-float-[0-9]*:../../print/tex-float
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-newfloat-[0-9]*:../../print/tex-newfloat
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-titlesec-[0-9]*:../../print/tex-titlesec
DEPENDS+=	tex-titling-[0-9]*:../../print/tex-titling
DEPENDS+=	tex-tocbibind-[0-9]*:../../print/tex-tocbibind
DEPENDS+=	tex-tocloft-[0-9]*:../../print/tex-tocloft

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
