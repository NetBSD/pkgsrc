# $NetBSD: Makefile,v 1.5 2004/07/29 05:54:11 xtraeme Exp $

DISTNAME=	XFree86-4.4.0-src-4
PKGNAME=	XFree86-fonts75dpi-${XF_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 bitmap 75dpi fonts

NO_XFREE86_TARGETS=	# defined
WRKSRC=			${WRKDIR}/xc/fonts/bdf/75dpi

CONFLICTS=	xorg-fonts75dpi-[0-9]*

.include "../../fonts/XFree86-fontsEncodings/Makefile.common"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
