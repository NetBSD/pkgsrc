# $NetBSD: Makefile,v 1.11 2020/01/18 23:34:17 rillig Exp $

DISTNAME=	ifluatex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.4
TEXLIVE_REV=	41247

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/ifluatex
COMMENT=	Documentation for tex-ifluatex
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-oberdiek-doc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
