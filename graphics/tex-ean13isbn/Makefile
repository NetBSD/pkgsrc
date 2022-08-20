# $NetBSD: Makefile,v 1.1 2022/08/20 23:02:41 wiz Exp $

DISTNAME=	ean13isbn
PKGNAME=	tex-${DISTNAME}-2022
TEXLIVE_REV=	57514

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ean13isbn
COMMENT=	Print EAN13 for ISBN
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ean-[0-9]*:../../fonts/tex-ean
DEPENDS+=	tex-kvoptions-[0-9]*:../../print/tex-kvoptions

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
