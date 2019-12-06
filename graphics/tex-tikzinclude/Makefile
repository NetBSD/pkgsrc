# $NetBSD: Makefile,v 1.2 2019/12/06 20:04:39 markd Exp $

DISTNAME=	tikzinclude
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	28715

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/tikzinclude
COMMENT=	Import TikZ images from colletions
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
