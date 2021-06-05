# $NetBSD: Makefile,v 1.15 2021/06/05 04:43:46 markd Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.655
TEXLIVE_REV=	59446

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
