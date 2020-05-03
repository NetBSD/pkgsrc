# $NetBSD: Makefile,v 1.11 2020/05/03 11:57:31 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2020
TEXLIVE_REV=	53641

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
