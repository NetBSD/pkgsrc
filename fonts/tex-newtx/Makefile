# $NetBSD: Makefile,v 1.12 2020/05/10 04:31:50 markd Exp $

DISTNAME=	newtx
PKGNAME=	tex-${DISTNAME}-1.625
PKGREVISION=	1
TEXLIVE_REV=	54080

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/newtx
COMMENT=	Alternative uses of the TX fonts, with improved metrics
LICENSE=	lppl-1.3c

DEPENDS+=	tex-kastrup-[0-9]*:../../math/tex-kastrup

TEX_MAP_FILES+=	newtx.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
