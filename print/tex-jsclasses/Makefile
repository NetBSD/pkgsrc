# $NetBSD: Makefile,v 1.9 2019/08/11 11:27:36 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2019.51726
TEXLIVE_REV=	51726

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
