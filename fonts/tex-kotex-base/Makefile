# $NetBSD: Makefile,v 1.6 2014/01/08 05:12:08 minskim Exp $

DISTNAME=	kotex-base
PKGNAME=	tex-${DISTNAME}-0.3
PKGREVISION=	1
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/texlive/2013/archive/
DIST_SUBDIR=	${PKGNAME_NOREV}-${TEXLIVE_REV}
TEXLIVE_REV=	4

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	Type1/TTF of unbatang, undotum, untaza, and ungraphic

TEX_MAP_FILES+=	kotex-base.map

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
