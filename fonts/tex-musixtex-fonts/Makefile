# $NetBSD: Makefile,v 1.4 2019/12/06 19:30:17 markd Exp $

DISTNAME=	musixtex-fonts
PKGNAME=	tex-${DISTNAME}-2015
TEXLIVE_REV=	37762

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/musixtex-fonts
COMMENT=	Fonts used by MusixTeX
LICENSE=	gnu-gpl-v2

TEX_MIXEDMAP_FILES+=	musix.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
