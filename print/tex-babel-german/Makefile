# $NetBSD: Makefile,v 1.5 2019/12/06 20:18:53 markd Exp $

DISTNAME=	babel-german
PKGNAME=	tex-${DISTNAME}-2.11
TEXLIVE_REV=	49391

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/babel-german
COMMENT=	Babel support for documents written in German
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
