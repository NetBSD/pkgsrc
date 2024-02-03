# $NetBSD: Makefile,v 1.20 2024/02/03 02:39:35 markd Exp $

DISTNAME=	animate
PKGNAME=	tex-${DISTNAME}-20230618
TEXLIVE_REV=	67401

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/animate
COMMENT=	Create PDF and SVG animations from graphics files and inline graphics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
