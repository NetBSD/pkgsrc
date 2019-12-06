# $NetBSD: Makefile,v 1.8 2019/12/06 20:19:31 markd Exp $

DISTNAME=	eso-pic
PKGNAME=	tex-${DISTNAME}-2.0h
TEXLIVE_REV=	47694

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/eso-pic
COMMENT=	Add picture commands (or backgrounds) to every page
LICENSE=	lppl-1.2

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
