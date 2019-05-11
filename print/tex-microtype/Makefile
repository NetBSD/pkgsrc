# $NetBSD: Makefile,v 1.9 2019/05/11 22:17:52 markd Exp $

DISTNAME=	microtype
PKGNAME=	tex-${DISTNAME}-2.7b
TEXLIVE_REV=	50187

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/microtype
COMMENT=	Interface to the micro-typographic features of pdfTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-pdftex>=1.30:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
