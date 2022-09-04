# $NetBSD: Makefile,v 1.6 2022/09/04 21:03:43 markd Exp $

DISTNAME=	latex-base-dev
PKGNAME=	tex-${DISTNAME}-20221101pre1
PKGREVISION=	1
TEXLIVE_REV=	63922

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/latex-base-dev
COMMENT=	Development pre-release of the LaTeX kernel
LICENSE=	lppl-1.3c

DEPENDS+=	tex-hypdoc-[0-9]*:../../print/tex-hypdoc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
