# $NetBSD: Makefile,v 1.3 2016/01/26 11:23:05 markd Exp $

DISTNAME=	seminar
PKGNAME=	tex-${DISTNAME}-1.61
TEXLIVE_REV=	34011

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Make overhead slides
LICENSE=	lppl-1.2

CONFLICTS+=	teTeX-texmf<=3.0nb30
DEPENDS+=	tex-2up-[0-9]*:../../print/tex-2up
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xcomment-[0-9]*:../../print/tex-xcomment

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
