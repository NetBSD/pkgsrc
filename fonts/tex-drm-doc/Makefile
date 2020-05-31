# $NetBSD: Makefile,v 1.6 2020/05/31 09:23:02 rillig Exp $

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
# not used during the build
CHECK_PORTABILITY_SKIP=	share/texmf-dist/doc/fonts/drm/allconvert.sh

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
