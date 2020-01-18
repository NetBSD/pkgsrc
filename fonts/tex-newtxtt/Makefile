# $NetBSD: Makefile,v 1.5 2020/01/18 23:31:45 rillig Exp $

DISTNAME=	newtxtt
PKGNAME=	tex-${DISTNAME}-1.055
TEXLIVE_REV=	44510

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ctan.org/pkg/newtxtt
COMMENT=	Enhancement of typewriter fonts from newtx
LICENSE=	gnu-gpl-v3 AND lppl-1.3c

TEX_MAP_FILES+=	newtxtt.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
