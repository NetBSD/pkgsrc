# $NetBSD: Makefile,v 1.13 2020/05/11 11:23:57 markd Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.626
TEXLIVE_REV=	55012

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
