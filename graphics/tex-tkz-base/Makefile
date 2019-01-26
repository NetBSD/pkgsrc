# $NetBSD: Makefile,v 1.3 2019/01/26 08:04:32 markd Exp $

DISTNAME=	tkz-base
PKGNAME=	tex-${DISTNAME}-1.16d
TEXLIVE_REV=	48710

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tkz-base
COMMENT=	Tools for drawing with a cartesian coordinate system
LICENSE=	lppl-1.3c

DEPENDS+=       tex-numprint-[0-9]*:../../print/tex-numprint
DEPENDS+=       tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
