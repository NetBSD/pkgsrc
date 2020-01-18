# $NetBSD: Makefile,v 1.9 2020/01/18 23:34:28 rillig Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.21
TEXLIVE_REV=	46250

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
