# $NetBSD: Makefile,v 1.2 2021/06/03 05:25:16 markd Exp $

DISTNAME=	bxjscls
PKGNAME=	tex-${DISTNAME}-2.5a
TEXLIVE_REV=	59253

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxjscls
COMMENT=	Japanese document class collection for all major engines
LICENSE=	2-clause-bsd

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
