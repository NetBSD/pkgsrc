# $NetBSD: Makefile,v 1.4 2016/01/27 10:21:53 markd Exp $

DISTNAME=	leaflet
PKGNAME=	tex-${DISTNAME}-1.0e
TEXLIVE_REV=	32093

MAINTAINER=	leot1990@users.sourceforge.net
COMMENT=	Create small handouts (flyers)
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-ms-[0-9]*:../../print/tex-ms
DEPENDS+=	tex-psnfss-[0-9]*:../../fonts/tex-psnfss
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
