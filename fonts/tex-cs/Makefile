# $NetBSD: Makefile,v 1.3 2016/08/07 07:17:36 markd Exp $

DISTNAME=	cs
PKGNAME=	tex-${DISTNAME}-2016.41553
TEXLIVE_REV=	41553

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/csfonts
COMMENT=	Czech/Slovak-tuned Computer Modern fonts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-cmexb-[0-9]*:../../fonts/tex-cmexb

TEX_MAP_FILES+=	cs-charter.map
TEX_MAP_FILES+=	csfonts.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
