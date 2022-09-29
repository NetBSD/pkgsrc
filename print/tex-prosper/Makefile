# $NetBSD: Makefile,v 1.20 2022/09/29 06:14:01 markd Exp $

DISTNAME=	prosper
PKGNAME=	tex-${DISTNAME}-1.5
TEXLIVE_REV=	15878

MAINTAINER=	nico@orgrim.net
HOMEPAGE=	https://ctan.org/pkg/prosper
COMMENT=	LaTeX class for high quality slides
LICENSE=	lppl-1.2

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-fp-[0-9]*:../../math/tex-fp
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-multido-[0-9]*:../../devel/tex-multido
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-seminar-[0-9]*:../../print/tex-seminar

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
