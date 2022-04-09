# $NetBSD: Makefile,v 1.6 2022/04/09 02:59:57 markd Exp $

DISTNAME=	seminar
PKGNAME=	tex-${DISTNAME}-1.63a
TEXLIVE_REV=	59801

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/seminar
COMMENT=	Make overhead slides
LICENSE=	lppl-1.2

DEPENDS+=	tex-2up-[0-9]*:../../print/tex-2up
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-pstricks-[0-9]*:../../graphics/tex-pstricks
DEPENDS+=	tex-xcomment-[0-9]*:../../print/tex-xcomment

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
