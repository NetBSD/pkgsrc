# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:35 rillig Exp $

DISTNAME=	tikzinclude
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	28715

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzinclude
COMMENT=	Import TikZ images from colletions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
