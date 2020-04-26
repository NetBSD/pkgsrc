# $NetBSD: Makefile,v 1.1 2020/04/26 12:21:22 markd Exp $

DISTNAME=	wasy-type1
PKGNAME=	tex-${DISTNAME}-001.002
TEXLIVE_REV=	53534

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/wasy-type1
COMMENT=	Type 1 versions of wasy fonts
LICENSE=	public-domain

DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy

TEX_MIXEDMAP_FILES+=	wasy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
