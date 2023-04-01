# $NetBSD: Makefile,v 1.9 2023/04/01 22:30:08 markd Exp $

DISTNAME=	tikzmark
PKGNAME=	tex-${DISTNAME}-1.15
TEXLIVE_REV=	64819

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzmark
COMMENT=	Use TikZ's method of remembering a position on a page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
