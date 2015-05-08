# $NetBSD: Makefile,v 1.1 2015/05/08 11:27:58 wiz Exp $

DISTNAME=	xits.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.108
TEXLIVE_REV=	32763

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xits
COMMENT=	Documentation for tex-xits
LICENSE=	ofl-v1.1

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xits/postprocess.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
