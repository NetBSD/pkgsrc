# $NetBSD: Makefile,v 1.15 2020/01/18 23:34:29 rillig Exp $

DISTNAME=	memoir
PKGNAME=	tex-${DISTNAME}-3.7h
TEXLIVE_REV=	49394

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/memoir
COMMENT=	Typeset fiction, non-fiction and mathematical books
LICENSE=	lppl-1.3c

DEPENDS+=	tex-ifxetex>=0.6:../../print/tex-ifxetex
DEPENDS+=	tex-oberdiek>=2009nb1:../../print/tex-oberdiek

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
