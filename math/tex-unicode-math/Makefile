# $NetBSD: Makefile,v 1.11 2020/04/27 02:20:52 markd Exp $

DISTNAME=	unicode-math
PKGNAME=	tex-${DISTNAME}-0.8q
TEXLIVE_REV=	53609

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/unicode-math
COMMENT=	Unicode mathematics support for XeTeX and LuaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel
DEPENDS+=	tex-lm-math-[0-9]*:../../fonts/tex-lm-math

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
