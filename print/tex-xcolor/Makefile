# $NetBSD: Makefile,v 1.11 2024/02/17 02:00:27 markd Exp $

DISTNAME=	xcolor
PKGNAME=	tex-${DISTNAME}-3.01
TEXLIVE_REV=	68864

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xcolor
COMMENT=	Driver-independent color extensions for LaTeX and pdfLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-colortbl-[0-9]*:../../print/tex-colortbl
DEPENDS+=	tex-graphics-cfg-[0-9]*:../../print/tex-graphics-cfg
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
