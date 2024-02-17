# $NetBSD: Makefile,v 1.17 2024/02/17 01:57:26 markd Exp $

DISTNAME=	xcharter.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.25
TEXLIVE_REV=	67742

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/xcharter
COMMENT=	Documentation for tex-xcharter
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altone.py
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altSRB.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
