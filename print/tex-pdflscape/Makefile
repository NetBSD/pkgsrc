# $NetBSD: Makefile,v 1.3 2026/03/31 07:42:44 markd Exp $

DISTNAME=	pdflscape
PKGNAME=	tex-${DISTNAME}-0.14
TEXLIVE_REV=	77682

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdflscape
COMMENT=	Make landscape pages display as landscape
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
