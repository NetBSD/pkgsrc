# $NetBSD: Makefile,v 1.3 2017/09/06 16:49:45 wiz Exp $

DISTNAME=	t2
PKGNAME=	tex-${DISTNAME}-2010
TEXLIVE_REV=	15878

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support for using T2 encoding
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
