# $NetBSD: Makefile,v 1.1 2021/02/21 10:15:32 markd Exp $

DISTNAME=	bxjscls
PKGNAME=	tex-${DISTNAME}-2.5
TEXLIVE_REV=	57625

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bxjscls
COMMENT=	Japanese document class collection for all major engines
LICENSE=	2-clause-bsd

DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
