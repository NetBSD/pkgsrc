# $NetBSD: Makefile,v 1.4 2018/05/13 10:22:05 markd Exp $

DISTNAME=	t2
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47458

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/t2
COMMENT=	Support for using T2 encoding
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
