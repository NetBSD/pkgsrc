# $NetBSD: Makefile,v 1.8 2019/12/06 20:22:03 markd Exp $

DISTNAME=	ms
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	51784

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ms
COMMENT=	Various LaTeX packages by Martin Schroeder
LICENSE=	lppl-1.3c

DEPENDS+=	tex-footmisc-[0-9]*:../../print/tex-footmisc
DEPENDS+=	tex-koma-script-[0-9]*:../../print/tex-koma-script
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
