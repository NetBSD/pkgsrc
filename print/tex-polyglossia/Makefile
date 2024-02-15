# $NetBSD: Makefile,v 1.17 2024/02/15 19:30:47 markd Exp $

DISTNAME=	polyglossia
PKGNAME=	tex-${DISTNAME}-1.66
TEXLIVE_REV=	69093

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/polyglossia
COMMENT=	An alternative to babel for XeLaTeX and LuaLaTeX
LICENSE=	mit AND lppl-1.3c AND cc0-1.0-universal

DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-filehook-[0-9]*:../../print/tex-filehook
DEPENDS+=	tex-fontspec-[0-9]*:../../fonts/tex-fontspec
DEPENDS+=	tex-iftex-[0-9]*:../../print/tex-iftex
DEPENDS+=	tex-makecmds-[0-9]*:../../print/tex-makecmds
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	xetex>=0.9995.3nb1:../../print/xetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
