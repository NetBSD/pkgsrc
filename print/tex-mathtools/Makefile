# $NetBSD: Makefile,v 1.14 2024/03/20 10:51:14 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.30
TEXLIVE_REV=	70596

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
