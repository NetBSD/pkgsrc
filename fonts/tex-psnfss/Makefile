# $NetBSD: Makefile,v 1.14 2020/05/10 04:31:52 markd Exp $

DISTNAME=	psnfss
PKGNAME=	tex-${DISTNAME}-9.3
PKGREVISION=	1
TEXLIVE_REV=	54694

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/psnfss
COMMENT=	Font support for common PostScript fonts
LICENSE=	lppl-1.3c

DEPENDS+=	tex-avantgar-[0-9]*:../../fonts/tex-avantgar
DEPENDS+=	tex-bookman-[0-9]*:../../fonts/tex-bookman
DEPENDS+=	tex-charter-[0-9]*:../../fonts/tex-charter
DEPENDS+=	tex-courier-[0-9]*:../../fonts/tex-courier
DEPENDS+=	tex-fpl-[0-9]*:../../fonts/tex-fpl
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-helvetic-[0-9]*:../../fonts/tex-helvetic
DEPENDS+=	tex-mathpazo-[0-9]*:../../fonts/tex-mathpazo
DEPENDS+=	tex-ncntrsbk-[0-9]*:../../fonts/tex-ncntrsbk
DEPENDS+=	tex-palatino-[0-9]*:../../fonts/tex-palatino
DEPENDS+=	tex-symbol-[0-9]*:../../fonts/tex-symbol
DEPENDS+=	tex-times-[0-9]*:../../fonts/tex-times
DEPENDS+=	tex-zapfchan-[0-9]*:../../fonts/tex-zapfchan
DEPENDS+=	tex-zapfding-[0-9]*:../../fonts/tex-zapfding

TEX_MAP_FILES+=	charter.map
TEX_MAP_FILES+=	fpls.map
TEX_MAP_FILES+=	pazo.map
TEX_MAP_FILES+=	utopia.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
