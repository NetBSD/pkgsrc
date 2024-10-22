# $NetBSD: Makefile,v 1.4 2024/10/22 22:16:07 markd Exp $

DISTNAME=	berenisadf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-2.1
TEXLIVE_REV=	72484

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/berenisadf
COMMENT=	Documentation for tex-berenisadf
LICENSE=	lppl-1.3c AND gnu-gpl-v2

# fontforge
CHECK_INTERPRETER_SKIP=	share/texmf-dist/doc/fonts/berenisadf/ff-ybd.pe

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
