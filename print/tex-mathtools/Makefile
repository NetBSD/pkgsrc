# $NetBSD: Makefile,v 1.10 2020/05/02 02:27:44 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.24
TEXLIVE_REV=	54516

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
