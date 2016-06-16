# $NetBSD: Makefile,v 1.2 2016/06/16 03:57:27 markd Exp $

DISTNAME=	cs
PKGNAME=	tex-${DISTNAME}-2016
TEXLIVE_REV=	40785

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/csfonts
COMMENT=	Czech/Slovak-tuned Computer Modern fonts
LICENSE=	gnu-gpl-v2

DEPENDS+=	tex-cmexb-[0-9]*:../../fonts/tex-cmexb

TEX_MAP_FILES+=	cs-charter.map
TEX_MAP_FILES+=	csfonts.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
