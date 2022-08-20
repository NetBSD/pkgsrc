# $NetBSD: Makefile,v 1.1 2022/08/20 23:31:53 wiz Exp $

DISTNAME=	sexam
PKGNAME=	tex-${DISTNAME}-1
TEXLIVE_REV=	46628

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/sexam
COMMENT=	Package for typesetting arabic exam scripts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-background-[0-9]*:../../print/tex-background
DEPENDS+=	tex-bclogo-[0-9]*:../../graphics/tex-bclogo
DEPENDS+=	tex-ean13isbn-[0-9]*:../../graphics/tex-ean13isbn
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-eulervm-[0-9]*:../../fonts/tex-eulervm
DEPENDS+=	tex-fancybox-[0-9]*:../../print/tex-fancybox
DEPENDS+=	tex-fmtcount-[0-9]*:../../print/tex-fmtcount
DEPENDS+=	tex-fouriernc-[0-9]*:../../fonts/tex-fouriernc
DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
# mathrsfs
DEPENDS+=	tex-jknapltx-[0-9]*:../../print/tex-jknapltx
DEPENDS+=	tex-listings-[0-9]*:../../print/tex-listings
DEPENDS+=	tex-mathtools-[0-9]*:../../print/tex-mathtools
DEPENDS+=	tex-moreenum-[0-9]*:../../print/tex-moreenum
# tikz
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf
DEPENDS+=	tex-polyglossia-[0-9]*:../../print/tex-polyglossia
# mathpple, pifont
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
# multicol
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-wasysym-[0-9]*:../../fonts/tex-wasysym
DEPENDS+=	tex-yagusylo-[0-9]*:../../print/tex-yagusylo

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
