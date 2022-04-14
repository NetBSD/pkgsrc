# $NetBSD: Makefile,v 1.9 2022/04/14 06:53:20 markd Exp $

DISTNAME=	xcolor
PKGNAME=	tex-${DISTNAME}-2.13
TEXLIVE_REV=	60925

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xcolor
COMMENT=	Driver-independent color extensions for LaTeX and pdfLaTeX
LICENSE=	lppl-1.2

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
