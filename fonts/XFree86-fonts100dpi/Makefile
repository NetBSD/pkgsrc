# $NetBSD: Makefile,v 1.13 2006/02/12 15:24:14 xtraeme Exp $

DISTNAME=	XFree86-${XF_VER}-src-4
PKGNAME=	XFree86-fonts100dpi-${XF_VER}
PKGREVISION=	3
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 bitmap 100dpi fonts

NO_XFREE86_TARGETS=	yes
WRKSRC=			${WRKDIR}/xc/fonts/bdf/100dpi

.include "../../fonts/XFree86-fontsEncodings/Makefile.common"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
