# $NetBSD: Makefile,v 1.8 2004/07/31 02:28:15 xtraeme Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	XFree86-fontsMisc-${XF_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	XFree86-${XF_VER}-src-1.tgz XFree86-${XF_VER}-src-4.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 default bitmap fonts

NO_XFREE86_TARGETS=	# defined
FONTS_MISC=		# defined
WRKSRC=			${WRKDIR}/xc/fonts/bdf/misc
EXTRACT_ONLY=		XFree86-${XF_VER}-src-4.tgz

.include "../../fonts/XFree86-fontsEncodings/Makefile.common"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
