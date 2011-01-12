# $NetBSD: Makefile,v 1.4 2011/01/12 15:18:12 minskim Exp $

DISTNAME=	kotex-dev
PKGNAME=	tex-${DISTNAME}-0.2
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/texlive/2010/archive/
DIST_SUBDIR=	${PKGNAME}
TEXLIVE_REV=	3

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	ko.TeX macros for luatex and xetex

DEPENDS+=	tex-amsfonts-[0-9]*:../../fonts/tex-amsfonts
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-euenc-[0-9]*:../../fonts/tex-euenc
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-kotex>=0.2:../../print/tex-kotex
DEPENDS+=	tex-kotex-base>=0.2:../../fonts/tex-kotex-base
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xltxtra-[0-9]*:../../print/tex-xltxtra
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
