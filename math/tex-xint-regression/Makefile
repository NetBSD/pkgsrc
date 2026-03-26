# $NetBSD: Makefile,v 1.2 2026/03/26 19:35:17 markd Exp $

DISTNAME=	xint-regression
PKGNAME=	tex-${DISTNAME}-0.1.3
TEXLIVE_REV=	77909

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xint-regression
COMMENT=	Classic regressions, with xint
LICENSE=	lppl-1.3c

DEPENDS+=	tex-listofitems-[0-9]*:../../print/tex-listofitems
DEPENDS+=	tex-simplekv-[0-9]*:../../print/tex-simplekv
DEPENDS+=	tex-xint-[0-9]*:../../math/tex-xint
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
