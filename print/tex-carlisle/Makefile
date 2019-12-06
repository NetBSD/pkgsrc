# $NetBSD: Makefile,v 1.10 2019/12/06 20:19:05 markd Exp $

DISTNAME=	carlisle
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47876

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/carlisle
COMMENT=	LaTeX packages created by David Carlisle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
