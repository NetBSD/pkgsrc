# $NetBSD: Makefile,v 1.11 2021/06/05 04:08:01 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.27
TEXLIVE_REV=	58856

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
