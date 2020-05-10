# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:50 markd Exp $

DISTNAME=	musixtex-fonts
PKGNAME=	tex-${DISTNAME}-2015
PKGREVISION=	1
TEXLIVE_REV=	37762

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/musixtex-fonts
COMMENT=	Fonts used by MusixTeX
LICENSE=	gnu-gpl-v2

TEX_MIXEDMAP_FILES+=	musix.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
