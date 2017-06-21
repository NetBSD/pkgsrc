# $NetBSD: Makefile,v 1.4 2017/06/21 13:25:35 markd Exp $

DISTNAME=	xcharter.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.08
TEXLIVE_REV=	43465

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xcharter
COMMENT=	Documentation for tex-xcharter
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altone.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
