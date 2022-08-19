# $NetBSD: Makefile,v 1.1 2022/08/19 19:40:37 wiz Exp $

DISTNAME=	arabi-add
PKGNAME=	tex-${DISTNAME}-1.0
TEXLIVE_REV=	37709

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/arabi-add
COMMENT=	Using hyperref and bookmark packages with arabic and farsi languages
LICENSE=	lppl-1.3c

DEPENDS+=	tex-bookmark-[0-9]*:../../print/tex-bookmark
DEPENDS+=	tex-datatool-[0-9]*:../../print/tex-datatool
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
