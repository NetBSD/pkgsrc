# $NetBSD: Makefile,v 1.7 2011/11/29 21:16:00 minskim Exp $

DISTNAME=	kotex
PKGNAME=	tex-${DISTNAME}-0.3
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/texlive/2011/archive/
DIST_SUBDIR=	${PKGNAME_NOREV}
TEXLIVE_REV=	1

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	ko.TeX macros to typeset Korean with etex or pdftex

DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-kotex-base>=0.1.1nb1:../../fonts/tex-kotex-base
DEPENDS+=	tex-kotex-utils>=0.1.1:../../print/tex-kotex-utils
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
DEPENDS+=	tex-ulem-[0-9]*:../../print/tex-ulem
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
