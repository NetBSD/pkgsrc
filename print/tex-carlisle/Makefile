# $NetBSD: Makefile,v 1.11 2020/01/18 23:33:44 rillig Exp $

DISTNAME=	carlisle
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47876

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/carlisle
COMMENT=	LaTeX packages created by David Carlisle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
