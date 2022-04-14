# $NetBSD: Makefile,v 1.8 2022/04/14 06:35:06 markd Exp $

DISTNAME=	tkz-base
PKGNAME=	tex-${DISTNAME}-4.05b
TEXLIVE_REV=	61947

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tkz-base
COMMENT=	Tools for drawing with a cartesian coordinate system
LICENSE=	lppl-1.3c

DEPENDS+=	tex-numprint-[0-9]*:../../print/tex-numprint
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
