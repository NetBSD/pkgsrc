# $NetBSD: Makefile,v 1.2 2019/12/06 20:21:28 markd Exp $

DISTNAME=	fundus-calligra
PKGNAME=	tex-${DISTNAME}-1.2
TEXLIVE_REV=	26018

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support for the calligra font in LaTeX documents
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
