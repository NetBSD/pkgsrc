# $NetBSD: Makefile,v 1.6 2020/05/10 04:31:42 markd Exp $

DISTNAME=	cs
PKGNAME=	tex-${DISTNAME}-2016.41553
PKGREVISION=	1
TEXLIVE_REV=	41553

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/csfonts
COMMENT=	Czech/Slovak-tuned Computer Modern fonts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-cmexb-[0-9]*:../../fonts/tex-cmexb

TEX_MAP_FILES+=	cs-charter.map
TEX_MAP_FILES+=	csfonts.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
