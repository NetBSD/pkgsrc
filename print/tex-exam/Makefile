# $NetBSD: Makefile,v 1.12 2024/02/03 04:50:36 markd Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.704
TEXLIVE_REV=	67600

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/exam
COMMENT=	Package for typesetting exam scripts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
