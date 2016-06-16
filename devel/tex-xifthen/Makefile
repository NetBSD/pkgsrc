# $NetBSD: Makefile,v 1.2 2016/06/16 03:54:44 markd Exp $

DISTNAME=	xifthen
PKGNAME=	tex-${DISTNAME}-1.4.0
TEXLIVE_REV=	38929

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extended conditional commands
LICENSE=	lppl-1.3c

DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-ifmtarg-[0-9]*:../../print/tex-ifmtarg
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
