# $NetBSD: Makefile,v 1.11 2021/06/03 07:00:11 markd Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	58023

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/exam
COMMENT=	Package for typesetting exam scripts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
