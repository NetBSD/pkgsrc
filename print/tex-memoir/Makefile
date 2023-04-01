# $NetBSD: Makefile,v 1.21 2023/04/01 12:00:10 markd Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.7.19
TEXLIVE_REV=	65040

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/memoir
COMMENT=	Typeset fiction, non-fiction and mathematical books
LICENSE=	lppl-1.3c

DEPENDS+=	tex-iftex>=1.0d:../../print/tex-iftex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
