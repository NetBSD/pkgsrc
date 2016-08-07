# $NetBSD: Makefile,v 1.3 2016/08/07 07:17:37 markd Exp $

DISTNAME=	xcharter.doc
PKGNAME=	tex-${DISTNAME:S/./-/}-1.078a
TEXLIVE_REV=	41393

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/xcharter
COMMENT=	Documentation for tex-xcharter
#LICENSE=	other-free

# we don't want a python dependency here
CHECK_INTERPRETER_SKIP+=	share/texmf-dist/doc/fonts/xcharter/altone.py

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
