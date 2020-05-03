# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:41 markd Exp $

DISTNAME=	magicnum
PKGNAME=	tex-${DISTNAME}-1.7
TEXLIVE_REV=	52983

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/magicnum
COMMENT=	Access TeX systems' "magic numbers"
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-infwarerr-[0-9]*:../../print/tex-infwarerr

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
