# $NetBSD: Makefile,v 1.6 2018/05/06 12:11:57 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	46918

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
