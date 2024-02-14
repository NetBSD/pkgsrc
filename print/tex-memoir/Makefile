# $NetBSD: Makefile,v 1.22 2024/02/14 19:36:47 markd Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.8.2
TEXLIVE_REV=	69600

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/memoir
COMMENT=	Typeset fiction, non-fiction and mathematical books
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
