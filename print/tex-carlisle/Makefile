# $NetBSD: Makefile,v 1.8 2017/12/23 19:06:32 markd Exp $

DISTNAME=	carlisle
PKGNAME=	tex-${DISTNAME}-2010
PKGREVISION=	1
TEXLIVE_REV=	18258

MAINTAINER=	minskim@NetBSD.org
COMMENT=	LaTeX packages created by David Carlisle
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
