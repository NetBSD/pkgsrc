# $NetBSD: Makefile,v 1.16 2026/03/30 08:09:47 markd Exp $

DISTNAME=	mathtools
PKGNAME=	tex-${DISTNAME}-1.31.78251
TEXLIVE_REV=	78251

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mathtools
COMMENT=	Mathematical tools to use with amsmath
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
