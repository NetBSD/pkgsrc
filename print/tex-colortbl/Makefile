# $NetBSD: Makefile,v 1.8 2019/12/06 20:19:11 markd Exp $

DISTNAME=	colortbl
PKGNAME=	tex-${DISTNAME}-1.0d
TEXLIVE_REV=	49404

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Add colour to LaTeX tables
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
