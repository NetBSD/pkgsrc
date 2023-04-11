# $NetBSD: Makefile,v 1.1 2023/04/11 03:03:03 markd Exp $

DISTNAME=	japanese-mathformulas
PKGNAME=	tex-${DISTNAME}-1.0.2
TEXLIVE_REV=	64678

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/japanese-mathformulas
COMMENT=	Compiling basic math formulas in Japanese using LuaLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-l3packages-[0-9]*:../../devel/tex-l3packages
DEPENDS+=	tex-luatexja-[0-9]*:../../print/tex-luatexja
DEPENDS+=	tex-mathtools-[0-9]*:../../print/tex-mathtools
DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
