# $NetBSD: Makefile,v 1.3 2020/01/18 23:31:14 rillig Exp $

DISTNAME=	berenisadf.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.004
TEXLIVE_REV=	32215

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/berenisadf
COMMENT=	Documentation for tex-berenisadf
#LICENSE=	other-free

# fontforge
CHECK_INTERPRETER_SKIP=	share/texmf-dist/doc/fonts/berenisadf/ff-ybd.pe

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
