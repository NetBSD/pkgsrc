# $NetBSD: Makefile,v 1.1 2021/02/12 03:18:12 markd Exp $

DISTNAME=	lualatex-math
PKGNAME=	tex-${DISTNAME}-1.9
TEXLIVE_REV=	56541

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/lualatex-math
COMMENT=	Fixes for mathematics-related LuaLaTeX issues
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
