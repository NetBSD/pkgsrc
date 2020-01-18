# $NetBSD: Makefile,v 1.5 2020/01/18 23:31:25 rillig Exp $

DISTNAME=	drm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.4
TEXLIVE_REV=	38157

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/drm
COMMENT=	Documentation for tex-drm
LICENSE=	lppl-1.3c

REPLACE_SH+=		doc/fonts/drm/allfonts.sh
REPLACE_SH+=		doc/fonts/drm/convert.sh
# fontforge
CHECK_INTERPRETER_SKIP=	share/texmf-dist/doc/fonts/drm/fontconvert.sh

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
