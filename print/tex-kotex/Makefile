# $NetBSD: Makefile,v 1.3 2009/07/23 06:26:59 minskim Exp $
# TeX Live Revision 19

DISTNAME=	kotex
PKGNAME=	tex-${DISTNAME}-0.1.1
PKGREVISION=	1
MASTER_SITES=	http://ftp.ktug.or.kr/KTUG/texlive/2008/archive/
DIST_SUBDIR=	${PKGNAME_NOREV}-19

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/ko.TeX/
COMMENT=	TeX macro package to typeset Korean

DEPENDS+=	tex-bin-kotex-[0-9]*:../../print/tex-bin-kotex
DEPENDS+=	tex-cm-super-[0-9]*:../../fonts/tex-cm-super
DEPENDS+=	tex-enumitem-[0-9]*:../../print/tex-enumitem
DEPENDS+=	tex-etex-pkg-[0-9]*:../../print/tex-etex-pkg
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-kotex-base-[0-9]*:../../fonts/tex-kotex-base
DEPENDS+=	tex-latex-[0-9]*:../../print/tex-latex
DEPENDS+=	tex-ltxmisc-[0-9]*:../../print/tex-ltxmisc
DEPENDS+=	tex-microtype-[0-9]*:../../print/tex-microtype
DEPENDS+=	tex-memoir-[0-9]*:../../print/tex-memoir
DEPENDS+=	tex-moreverb-[0-9]*:../../print/tex-moreverb
DEPENDS+=	tex-oberdiek-[0-9]*:../../print/tex-oberdiek
DEPENDS+=	tex-paralist-[0-9]*:../../print/tex-paralist
DEPENDS+=	tex-sectsty-[0-9]*:../../print/tex-sectsty
DEPENDS+=	tex-setspace-[0-9]*:../../print/tex-setspace
DEPENDS+=	tex-tools-[0-9]*:../../print/tex-tools
DEPENDS+=	tex-type1cm-[0-9]*:../../print/tex-type1cm
DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../print/texlive/module.mk"
.include "../../mk/bsd.pkg.mk"
