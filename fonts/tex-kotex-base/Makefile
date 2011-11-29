# $NetBSD: Makefile,v 1.5 2011/11/29 20:35:32 minskim Exp $

DISTNAME=	kotex-base
PKGNAME=	tex-${DISTNAME}-0.3
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/texlive/2011/archive/
DIST_SUBDIR=	${PKGNAME}-${TEXLIVE_REV}
TEXLIVE_REV=	1

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	Type1 and TTF fonts of unbatang, undotum, untaza, and ungraphic

TEX_MAP_FILES+=	kotex-base.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
