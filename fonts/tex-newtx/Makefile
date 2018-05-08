# $NetBSD: Makefile,v 1.7 2018/05/08 10:55:32 markd Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.531
TEXLIVE_REV=	47160

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
