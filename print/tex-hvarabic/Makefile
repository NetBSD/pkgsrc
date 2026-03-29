# $NetBSD: Makefile,v 1.2 2026/03/29 10:55:32 markd Exp $

DISTNAME=	hvarabic
PKGNAME=	tex-${DISTNAME}-0.02.76924
TEXLIVE_REV=	76924

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/hvarabic
COMMENT=	Macros for RTL typesetting
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
