# $NetBSD: Makefile,v 1.2 2017/10/15 20:32:28 markd Exp $

DISTNAME=	tkz-base
PKGNAME=	tex-${DISTNAME}-1.16
TEXLIVE_REV=	22961

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tkz-base
COMMENT=	Tools for drawing with a cartesian coordinate system
LICENSE=	lppl-1.3c

DEPENDS+=       tex-numprint-[0-9]*:../../print/tex-numprint
DEPENDS+=       tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
