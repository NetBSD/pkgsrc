# $NetBSD: Makefile,v 1.13 2022/09/01 04:41:50 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.29
TEXLIVE_REV=	63767

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
