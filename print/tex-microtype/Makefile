# $NetBSD: Makefile,v 1.13 2021/02/13 11:15:31 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	57096

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
