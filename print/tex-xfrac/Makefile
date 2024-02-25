# $NetBSD: Makefile,v 1.1 2024/02/25 19:34:52 markd Exp $

DISTNAME=	xfrac
PKGNAME=	tex-${DISTNAME}-2023
TEXLIVE_REV=	69888

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xfrac
COMMENT=	Split-level fractions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
