# $NetBSD: Makefile,v 1.10 2022/09/01 05:49:54 markd Exp $

DISTNAME=	xcolor
PKGNAME=	tex-${DISTNAME}-2.14
TEXLIVE_REV=	63563

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xcolor
COMMENT=	Driver-independent color extensions for LaTeX and pdfLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
