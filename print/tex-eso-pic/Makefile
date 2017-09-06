# $NetBSD: Makefile,v 1.6 2017/09/06 16:49:33 wiz Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-2.0g
TEXLIVE_REV=	37925

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eso-pic
COMMENT=	Add picture commands (or backgrounds) to every page
LICENSE=	lppl-1.2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
