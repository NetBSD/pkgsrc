# $NetBSD: Makefile,v 1.5 2017/10/23 09:01:04 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2017.45473
TEXLIVE_REV=	45473

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
