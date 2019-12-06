# $NetBSD: Makefile,v 1.10 2019/12/06 20:19:32 markd Exp $

DISTNAME=	etex-pkg
PKGNAME=	tex-${DISTNAME}-2.7
TEXLIVE_REV=	41784

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/etex-pkg
COMMENT=	E-TeX support package
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
