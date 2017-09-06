# $NetBSD: Makefile,v 1.4 2017/09/06 16:49:44 wiz Exp $

DISTNAME=	seminar
PKGNAME=	tex-${DISTNAME}-1.61
TEXLIVE_REV=	34011

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Make overhead slides
LICENSE=	lppl-1.2

DEPENDS+=	tex-2up-[0-9]*:../../print/tex-2up
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xcomment-[0-9]*:../../print/tex-xcomment

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
