# $NetBSD: Makefile,v 1.19 2024/12/26 18:17:24 riastradh Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.742
PKGREVISION=	1
TEXLIVE_REV=	70491

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-carlisle-[0-9]*:../../print/tex-carlisle
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-fontaxes-[0-9]*:../../print/tex-fontaxes
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-mweights-[0-9]*:../../print/tex-mweights
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-txfonts-[0-9]*:../../fonts/tex-txfonts
DEPENDS+=	tex-xcolor-[0-9]*:../../print/tex-xcolor
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xpatch-[0-9]*:../../print/tex-xpatch
DEPENDS+=	tex-xstring-[0-9]*:../../print/tex-xstring

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
