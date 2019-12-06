# $NetBSD: Makefile,v 1.2 2019/12/06 20:18:58 markd Exp $

DISTNAME=	bagpipe
PKGNAME=	tex-${DISTNAME}-3.02
TEXLIVE_REV=	34393

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/bagpipe
COMMENT=	Support for typesetting bagpipe music
LICENSE=	lppl-1.3c

DEPENDS+=	tex-musixtex>=1.15:../../print/tex-musixtex

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
