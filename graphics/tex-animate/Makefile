# $NetBSD: Makefile,v 1.16 2022/04/07 05:06:50 markd Exp $

DISTNAME=	animate
PKGNAME=	tex-${DISTNAME}-20220221
TEXLIVE_REV=	62123

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/animate
COMMENT=	Create PDF and SVG animations from graphics files and inline graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
