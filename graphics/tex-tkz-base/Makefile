# $NetBSD: Makefile,v 1.7 2020/04/27 02:08:15 markd Exp $

DISTNAME=	tkz-base
PKGNAME=	tex-${DISTNAME}-3.06c
TEXLIVE_REV=	54758

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tkz-base
COMMENT=	Tools for drawing with a cartesian coordinate system
LICENSE=	lppl-1.3c

DEPENDS+=	tex-numprint-[0-9]*:../../print/tex-numprint
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
