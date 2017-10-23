# $NetBSD: Makefile,v 1.6 2017/10/23 02:02:00 markd Exp $

DISTNAME=	xcharter.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.1
TEXLIVE_REV=	45369

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xcharter
COMMENT=	Documentation for tex-xcharter
LICENSE=	lppl-1.3c

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altone.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
