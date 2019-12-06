# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:43 markd Exp $

DISTNAME=	ifluatex
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	41247

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ifluatex
COMMENT=	The \ifluatex switch for TeX
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-oberdiek<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
