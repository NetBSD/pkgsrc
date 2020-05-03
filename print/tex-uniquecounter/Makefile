# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:44 markd Exp $

DISTNAME=	uniquecounter
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	53162

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/uniquecounter
COMMENT=	Provides unlimited unique counter
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bigintcalc-[0-9]*:../../print/tex-bigintcalc
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
