# $NetBSD: Makefile,v 1.9 2022/09/01 05:41:07 markd Exp $

DISTNAME=	tkz-base
PKGNAME=	tex-${DISTNAME}-4.2c
TEXLIVE_REV=	63906

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tkz-base
COMMENT=	Tools for drawing with a cartesian coordinate system
LICENSE=	lppl-1.3c

DEPENDS+=	tex-numprint-[0-9]*:../../print/tex-numprint
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
