# $NetBSD: Makefile,v 1.1 2015/05/08 11:27:38 wiz Exp $

DISTNAME=	drm.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-4.1
TEXLIVE_REV=	36735

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
