# $NetBSD: Makefile,v 1.4 2019/12/06 19:32:15 markd Exp $

DISTNAME=	newtxtt
PKGNAME=	tex-${DISTNAME}-1.055
TEXLIVE_REV=	44510

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/newtxtt
COMMENT=	Enhancement of typewriter fonts from newtx
LICENSE=	gnu-gpl-v3 AND lppl-1.3c

TEX_MAP_FILES+=	newtxtt.map

TEXLIVE_UNVERSIONED=	yes
.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
