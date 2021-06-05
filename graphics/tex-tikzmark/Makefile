# $NetBSD: Makefile,v 1.8 2021/06/05 06:47:48 markd Exp $

DISTNAME=	tikzmark
PKGNAME=	tex-${DISTNAME}-1.10
TEXLIVE_REV=	57843

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzmark
COMMENT=	Use TikZ's method of remembering a position on a page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
