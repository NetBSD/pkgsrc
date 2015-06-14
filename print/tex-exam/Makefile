# $NetBSD: Makefile,v 1.6 2015/06/14 12:50:02 markd Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	37279

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/exam
COMMENT=	Package for typesetting exam scripts
LICENSE=	lppl-1.3c

CONFLICTS+=	teTeX-texmf<=3.0nb13
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
