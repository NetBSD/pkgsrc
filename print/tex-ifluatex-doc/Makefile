# $NetBSD: Makefile,v 1.10 2019/12/06 20:21:43 markd Exp $

DISTNAME=	ifluatex.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.4
TEXLIVE_REV=	41247

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/ifluatex
COMMENT=	Documentation for tex-ifluatex
LICENSE=	lppl-1.3c

CONFLICTS+=	tex-oberdiek-doc<2009

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
