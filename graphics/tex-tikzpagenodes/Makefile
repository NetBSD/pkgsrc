# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:36 rillig Exp $

DISTNAME=	tikzpagenodes
PKGNAME=	tex-${DISTNAME}-1.1
TEXLIVE_REV=	27723

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzpagenodes
COMMENT=	A single TikZ node for the whole page
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
