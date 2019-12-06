# $NetBSD: Makefile,v 1.8 2019/12/06 20:21:58 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.21
TEXLIVE_REV=	46250

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
