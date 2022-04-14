# $NetBSD: Makefile,v 1.12 2022/04/14 02:18:20 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.28a
TEXLIVE_REV=	61937

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
