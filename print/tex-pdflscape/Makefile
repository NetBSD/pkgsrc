# $NetBSD: Makefile,v 1.2 2023/04/01 21:49:59 markd Exp $

DISTNAME=	pdflscape
PKGNAME=	tex-${DISTNAME}-0.13
TEXLIVE_REV=	64851

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdflscape
COMMENT=	Make landscape pages display as landscape
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
