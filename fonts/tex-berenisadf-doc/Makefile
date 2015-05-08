# $NetBSD: Makefile,v 1.1 2015/05/08 11:27:32 wiz Exp $

DISTNAME=	berenisadf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.004
TEXLIVE_REV=	32215

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/berenisadf
COMMENT=	Documentation for tex-berenisadf
#LICENSE=	other-free

# fontforge
CHECK_INTERPRETER_SKIP=	share/texmf-dist/doc/fonts/berenisadf/ff-ybd.pe

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
