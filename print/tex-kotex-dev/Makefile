# $NetBSD: Makefile,v 1.1.1.1 2009/08/09 06:53:39 minskim Exp $
# TeX Live Revision 106

DISTNAME=	kotex-dev
PKGNAME=	tex-${DISTNAME}-0.1.1
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/texlive/2008/archive/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	Development version of tex-kotex

DEPENDS+=	tex-ams-[0-9]*:../../print/tex-ams
DEPENDS+=	tex-amsmath-[0-9]*:../../print/tex-amsmath
DEPENDS+=	tex-euenc-[0-9]*:../../fonts/tex-euenc
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex
DEPENDS+=	tex-kotex-[0-9]*:../../print/tex-kotex
DEPENDS+=	tex-kotex-base-[0-9]*:../../fonts/tex-kotex-base
DEPENDS+=	tex-lm-[0-9]*:../../fonts/tex-lm
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval
DEPENDS+=	tex-xltxtra-[0-9]*:../../print/tex-xltxtra
DEPENDS+=	tex-xunicode-[0-9]*:../../print/tex-xunicode

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
