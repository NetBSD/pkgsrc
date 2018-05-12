# $NetBSD: Makefile,v 1.8 2018/05/12 01:11:05 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.7a
TEXLIVE_REV=	46323

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/microtype
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
