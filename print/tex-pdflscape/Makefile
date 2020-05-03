# $NetBSD: Makefile,v 1.1 2020/05/03 05:30:42 markd Exp $

DISTNAME=	pdflscape
PKGNAME=	tex-${DISTNAME}-0.12
TEXLIVE_REV=	53047

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/pdflscape
COMMENT=	Make landscape pages display as landscape
LICENSE=	lppl-1.3c

DEPENDS+=	tex-atbegshi-[0-9]*:../../print/tex-atbegshi
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
