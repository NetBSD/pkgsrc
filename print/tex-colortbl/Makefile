# $NetBSD: Makefile,v 1.11 2021/02/26 21:09:25 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0e
PKGREVISION=	1
TEXLIVE_REV=	53545

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/colortbl
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
