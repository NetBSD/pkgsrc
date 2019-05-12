# $NetBSD: Makefile,v 1.8 2019/05/12 03:57:46 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2019
TEXLIVE_REV=	50813

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
