# $NetBSD: Makefile,v 1.4 2004/03/28 22:06:15 xtraeme Exp $

DISTNAME=	XFree86-4.4.0-src-4
PKGNAME=	XFree86-fonts100dpi-${XF_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 bitmap 100dpi fonts

NO_XFREE86_TARGETS=	# defined
WRKSRC=			${WRKDIR}/xc/fonts/bdf/100dpi

.include "../../fonts/XFree86-fontsEncodings/Makefile.common"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
