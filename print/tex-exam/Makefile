# $NetBSD: Makefile,v 1.10 2020/01/18 23:34:06 rillig Exp $

DISTNAME=	exam
PKGNAME=	tex-${DISTNAME}-2.603
TEXLIVE_REV=	46084

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/exam
COMMENT=	Package for typesetting exam scripts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
