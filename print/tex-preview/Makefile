# $NetBSD: Makefile,v 1.9 2020/01/18 23:34:42 rillig Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-11.91
TEXLIVE_REV=	44883

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
