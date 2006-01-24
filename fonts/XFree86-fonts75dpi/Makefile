# $NetBSD: Makefile,v 1.11 2006/01/24 07:32:07 wiz Exp $

DISTNAME=	XFree86-${XF_VER}-src-4
PKGNAME=	XFree86-fonts75dpi-${XF_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 bitmap 75dpi fonts

NO_XFREE86_TARGETS=	yes
WRKSRC=			${WRKDIR}/xc/fonts/bdf/75dpi

.include "../../fonts/XFree86-fontsEncodings/Makefile.common"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
