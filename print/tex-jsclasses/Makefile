# $NetBSD: Makefile,v 1.13 2022/04/14 01:51:19 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-20210628
TEXLIVE_REV=	59795

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
