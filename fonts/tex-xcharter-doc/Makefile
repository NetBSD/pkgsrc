# $NetBSD: Makefile,v 1.8 2019/01/26 02:15:06 markd Exp $

DISTNAME=	xcharter.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.116
TEXLIVE_REV=	48498

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xcharter
COMMENT=	Documentation for tex-xcharter
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altone.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
