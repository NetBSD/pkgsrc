# $NetBSD: Makefile,v 1.7 2020/01/18 23:34:42 rillig Exp $

DISTNAME=	polyglossia
PKGNAME=	tex-${DISTNAME}-1.44
TEXLIVE_REV=	50787

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/polyglossia
COMMENT=	An alternative to babel for XeLaTeX and LuaLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox>=2.1d:../../devel/tex-etoolbox
DEPENDS+=	tex-fontspec>=2.4c:../../fonts/tex-fontspec
DEPENDS+=	tex-makecmds-[0-9]*:../../print/tex-makecmds
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
