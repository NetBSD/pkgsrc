# $NetBSD: Makefile,v 1.8 2019/12/06 20:23:06 markd Exp $

DISTNAME=	preview
PKGNAME=	tex-${DISTNAME}-11.91
TEXLIVE_REV=	44883

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/preview
COMMENT=	Extract bits of a LaTeX source for output
LICENSE=	gnu-gpl-v3

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
