# $NetBSD: Makefile,v 1.3 2016/06/16 03:57:27 markd Exp $

DISTNAME=	drm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.4
TEXLIVE_REV=	38157

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/drm
COMMENT=	Documentation for tex-drm
LICENSE=	lppl-1.3c

REPLACE_SH+=		doc/fonts/drm/allfonts.sh
REPLACE_SH+=		doc/fonts/drm/convert.sh
# fontforge
CHECK_INTERPRETER_SKIP=	share/texmf-dist/doc/fonts/drm/fontconvert.sh

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
