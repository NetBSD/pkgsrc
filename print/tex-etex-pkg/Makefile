# $NetBSD: Makefile,v 1.9 2017/09/06 16:49:34 wiz Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	41784

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex-pkg
COMMENT=	E-TeX support package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
