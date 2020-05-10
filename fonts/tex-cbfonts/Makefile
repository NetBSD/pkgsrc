# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:40 markd Exp $

DISTNAME=	cbfonts
PKGNAME=	tex-${DISTNAME}-2014
PKGREVISION=	2
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
