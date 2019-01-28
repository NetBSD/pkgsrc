# $NetBSD: Makefile,v 1.7 2019/01/28 11:05:21 markd Exp $

DISTNAME=	jsclasses
PKGNAME=	tex-${DISTNAME}-2018.49387
TEXLIVE_REV=	49387

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/jsclasses
COMMENT=	Classes tailored for use with Japanese
LICENSE=	modified-bsd

DEPENDS+=	tex-ptex>=3.1.9:../../print/tex-ptex
SUPERSEDES+=	ja-jsclasses<071024nb1

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
