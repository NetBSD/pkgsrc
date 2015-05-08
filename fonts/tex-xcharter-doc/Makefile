# $NetBSD: Makefile,v 1.1 2015/05/08 11:27:58 wiz Exp $

DISTNAME=	xcharter.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.074
TEXLIVE_REV=	36562

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xcharter
COMMENT=	Documentation for tex-xcharter
#LICENSE=	other-free

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altone.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
