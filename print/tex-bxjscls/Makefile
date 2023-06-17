# $NetBSD: Makefile,v 1.4 2023/06/17 10:03:57 markd Exp $

DISTNAME=	bxjscls
PKGNAME=	tex-${DISTNAME}-2.8
TEXLIVE_REV=	67364

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxjscls
COMMENT=	Japanese document class collection for all major engines
LICENSE=	2-clause-bsd

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
