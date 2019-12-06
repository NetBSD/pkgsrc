# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:45 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2019.51726
TEXLIVE_REV=	51726

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
