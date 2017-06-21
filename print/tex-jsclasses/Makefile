# $NetBSD: Makefile,v 1.4 2017/06/21 07:24:08 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2017
TEXLIVE_REV=	43403

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
