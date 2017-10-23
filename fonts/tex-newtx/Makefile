# $NetBSD: Makefile,v 1.6 2017/10/23 00:47:19 markd Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.527
TEXLIVE_REV=	45279

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
