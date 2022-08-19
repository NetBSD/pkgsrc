# $NetBSD: Makefile,v 1.1 2022/08/19 20:09:27 wiz Exp $

DISTNAME=	hvarabic
PKGNAME=	tex-${DISTNAME}-0.02
TEXLIVE_REV=	59423

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hvarabic
COMMENT=	Macros for RTL typesetting
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
