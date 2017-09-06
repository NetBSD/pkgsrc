# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:40 wiz Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	44791

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/microtype
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
