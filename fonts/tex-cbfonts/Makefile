# $NetBSD: Makefile,v 1.5 2020/01/18 23:31:17 rillig Exp $

DISTNAME=	cbfonts
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	1
TEXLIVE_REV=	31624

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/cbgreek-complete
COMMENT=	Complete set of Greek fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-cbfonts-fd-[0-9]*:../../fonts/tex-cbfonts-fd

TEX_MIXEDMAP_FILES+=	cbgreek-full.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
