# $NetBSD: Makefile,v 1.2 2017/08/23 23:25:22 markd Exp $

DISTNAME=	unicode-math
PKGNAME=	tex-${DISTNAME}-0.8f
TEXLIVE_REV=	44940

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/unicode-math
COMMENT=	Unicode mathematics support for XeTeX and LuaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-l3kernel-[0-9]*:../../devel/tex-l3kernel

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
