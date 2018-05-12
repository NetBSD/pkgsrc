# $NetBSD: Makefile,v 1.12 2018/05/12 01:03:12 markd Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.7g
TEXLIVE_REV=	47305

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/memoir
COMMENT=	Typeset fiction, non-fiction and mathematical books
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
