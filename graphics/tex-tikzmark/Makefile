# $NetBSD: Makefile,v 1.6 2019/12/06 20:04:40 markd Exp $

DISTNAME=	tikzmark
PKGNAME=	tex-${DISTNAME}-1.7
TEXLIVE_REV=	51050

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzmark
COMMENT=	Use TikZ's method of remembering a position on a page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
