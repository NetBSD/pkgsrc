# $NetBSD: Makefile,v 1.34 2024/02/25 19:45:16 markd Exp $

DISTNAME=	oberdiek
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	69038

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/oberdiek
COMMENT=	Bundle of packages submitted by Heiko Oberdiek
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-auxhook-[0-9]*:../../print/tex-auxhook
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-grfext-[0-9]*:../../print/tex-grfext
DEPENDS+=	tex-grffile-[0-9]*:../../print/tex-grffile
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-pdftexcmds-[0-9]*:../../print/tex-pdftexcmds
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
