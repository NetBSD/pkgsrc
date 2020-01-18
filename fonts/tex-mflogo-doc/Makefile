# $NetBSD: Makefile,v 1.9 2020/01/18 23:31:43 rillig Exp $

DISTNAME=	mflogo.doc
# should be
#PKGNAME=	tex-${DISTNAME:S/./-/}-2.0
PKGNAME=	tex-${DISTNAME:S/./-/}-2016
TEXLIVE_REV=	38628

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/mflogo
COMMENT=	Documentation for tex-mflogo
LICENSE=	lppl-1.3c

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
