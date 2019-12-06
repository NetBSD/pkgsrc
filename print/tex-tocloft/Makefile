# $NetBSD: Makefile,v 1.5 2019/12/06 20:23:32 markd Exp $

DISTNAME=	tocloft
PKGNAME=	tex-${DISTNAME}-2.3i
TEXLIVE_REV=	45188

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tocloft
COMMENT=	Control table of contents, figures, etc
LICENSE=	lppl-1.3c

DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
