# $NetBSD: Makefile,v 1.14 2020/05/10 22:06:16 markd Exp $

DISTNAME=	animate
PKGNAME=	tex-${DISTNAME}-20200507
TEXLIVE_REV=	55056

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/animate
COMMENT=	Create PDF and SVG animations from graphics files and inline graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
