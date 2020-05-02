# $NetBSD: Makefile,v 1.12 2020/05/02 02:27:44 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.7d
TEXLIVE_REV=	52853

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/microtype
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
