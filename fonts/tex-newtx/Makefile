# $NetBSD: Makefile,v 1.8 2019/01/24 09:14:30 markd Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.554
TEXLIVE_REV=	47889

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
