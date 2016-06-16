# $NetBSD: Makefile,v 1.5 2016/06/16 04:06:11 markd Exp $

DISTNAME=	leaflet
PKGNAME=	tex-${DISTNAME}-1.1a
TEXLIVE_REV=	39683

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
