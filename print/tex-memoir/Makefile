# $NetBSD: Makefile,v 1.11 2017/09/06 16:49:40 wiz Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.7f
TEXLIVE_REV=	41203

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/memoir
COMMENT=	Typeset fiction, non-fiction and mathematical books
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
