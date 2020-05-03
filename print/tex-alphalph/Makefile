# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:34 markd Exp $

DISTNAME=	alphalph
PKGNAME=	tex-${DISTNAME}-2.6
TEXLIVE_REV=	53087

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/alphalph
COMMENT=	Convert numbers to letters
LICENSE=	lppl-1.3c

DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-intcalc-[0-9]*:../../print/tex-intcalc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
