# $NetBSD: Makefile,v 1.13 2020/04/27 02:08:12 markd Exp $

DISTNAME=	animate
PKGNAME=	tex-${DISTNAME}-20200425
TEXLIVE_REV=	54874

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/animate
COMMENT=	Create PDF and SVG animations from graphics files and inline graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
