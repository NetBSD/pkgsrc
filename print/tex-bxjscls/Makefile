# $NetBSD: Makefile,v 1.5 2024/02/03 03:07:43 markd Exp $

DISTNAME=	bxjscls
PKGNAME=	tex-${DISTNAME}-2.9b
TEXLIVE_REV=	69637

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxjscls
COMMENT=	Japanese document class collection for all major engines
LICENSE=	2-clause-bsd

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
