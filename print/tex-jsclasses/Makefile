# $NetBSD: Makefile,v 1.14 2023/04/08 10:36:07 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-20230224
TEXLIVE_REV=	66093

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
