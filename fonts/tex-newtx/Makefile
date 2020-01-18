# $NetBSD: Makefile,v 1.10 2020/01/18 23:31:44 rillig Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.554
TEXLIVE_REV=	47889

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
