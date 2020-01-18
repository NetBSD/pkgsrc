# $NetBSD: Makefile,v 1.3 2020/01/18 23:32:37 rillig Exp $

DISTNAME=	tikzscale
PKGNAME=	tex-${DISTNAME}-0.2.6
TEXLIVE_REV=	30637

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/tikzscale
COMMENT=	Resize pictures while respecting text size
LICENSE=	lppl-1.3c

DEPENDS+=	tex-pgf-[0-9]*:../../print/tex-pgf

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
