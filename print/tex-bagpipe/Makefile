# $NetBSD: Makefile,v 1.3 2020/01/18 23:33:41 rillig Exp $

DISTNAME=	bagpipe
PKGNAME=	tex-${DISTNAME}-3.02
TEXLIVE_REV=	34393

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/bagpipe
COMMENT=	Support for typesetting bagpipe music
LICENSE=	lppl-1.3c

DEPENDS+=	tex-musixtex>=1.15:../../print/tex-musixtex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
