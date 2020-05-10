# $NetBSD: Makefile,v 1.2 2020/05/10 04:31:56 markd Exp $

DISTNAME=	wasy-type1
PKGNAME=	tex-${DISTNAME}-001.002
PKGREVISION=	1
TEXLIVE_REV=	53534

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/wasy-type1
COMMENT=	Type 1 versions of wasy fonts
LICENSE=	public-domain

DEPENDS+=	tex-wasy-[0-9]*:../../fonts/tex-wasy

TEX_MIXEDMAP_FILES+=	wasy.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
