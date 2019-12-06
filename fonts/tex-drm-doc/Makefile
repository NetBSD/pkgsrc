# $NetBSD: Makefile,v 1.4 2019/12/06 19:29:51 markd Exp $

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

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
