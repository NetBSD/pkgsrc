# $NetBSD: Makefile,v 1.7 2017/09/06 16:49:34 wiz Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	37279

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/exam
COMMENT=	Package for typesetting exam scripts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
