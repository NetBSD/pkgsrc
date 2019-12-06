# $NetBSD: Makefile,v 1.6 2019/12/06 20:18:56 markd Exp $

DISTNAME=	babel-russian
PKGNAME=	tex-${DISTNAME}-1.3j
TEXLIVE_REV=	45007

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel-russian
COMMENT=	Russian language module for Babel
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
