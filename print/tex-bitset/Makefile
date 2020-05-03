# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:35 markd Exp $

DISTNAME=	bitset
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	53837

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bitset
COMMENT=	Handle bit-vector datatype
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bigintcalc-[0-9]*:../../print/tex-bigintcalc
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr
DEPENDS+=	tex-intcalc-[0-9]*:../../print/tex-intcalc

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
