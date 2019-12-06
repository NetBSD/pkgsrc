# $NetBSD: Makefile,v 1.2 2019/12/06 20:18:56 markd Exp $

DISTNAME=	babel-serbian
PKGNAME=	tex-${DISTNAME}-2.0
TEXLIVE_REV=	51651

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/babel-serbian
COMMENT=	Babel/Polyglossia support for Serbian
LICENSE=	lppl-1.3c

DEPENDS+=	tex-babel>=3.9l:../../print/tex-babel

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
