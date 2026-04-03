# $NetBSD: Makefile,v 1.20 2026/04/03 06:09:50 markd Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.1415926535
TEXLIVE_REV=	75712

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/plain
COMMENT=	The Plain TeX format
#LICENSE=	knuth

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-cm-[0-9]*:../../fonts/tex-cm
DEPENDS+=	tex-hyphen-base-[0-9]*:../../print/tex-hyphen-base
DEPENDS+=	tex-knuth-lib-[0-9]*:../../fonts/tex-knuth-lib

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
