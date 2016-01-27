# $NetBSD: Makefile,v 1.3 2016/01/27 10:28:32 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2014
TEXLIVE_REV=	34959

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
