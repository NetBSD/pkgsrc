# $NetBSD: Makefile,v 1.19 2021/06/06 12:24:14 markd Exp $

DISTNAME=	plain
PKGNAME=	tex-${DISTNAME}-3.141592653.57963
TEXLIVE_REV=	57963

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
