# $NetBSD: Makefile,v 1.12 2021/02/21 05:51:07 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-20201009
TEXLIVE_REV=	56608

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
