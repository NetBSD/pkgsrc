# $NetBSD: Makefile,v 1.18 2023/04/01 10:17:09 markd Exp $

DISTNAME=	animate
PKGNAME=	tex-${DISTNAME}-20220915
TEXLIVE_REV=	64401

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/animate
COMMENT=	Create PDF and SVG animations from graphics files and inline graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
