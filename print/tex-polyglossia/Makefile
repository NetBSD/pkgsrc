# $NetBSD: Makefile,v 1.3 2016/07/29 09:33:42 wiz Exp $

DISTNAME=	polyglossia
PKGNAME=	tex-${DISTNAME}-1.42.4
PKGREVISION=	1
TEXLIVE_REV=	40138

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/polyglossia
COMMENT=	An alternative to babel for XeLaTeX and LuaLaTeX
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etoolbox>=2.1d:../../devel/tex-etoolbox
DEPENDS+=	tex-fontspec>=2.4c:../../fonts/tex-fontspec
DEPENDS+=	tex-makecmds-[0-9]*:../../print/tex-makecmds
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
