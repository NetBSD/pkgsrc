# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 04:57:51 xtraeme Exp $

DISTNAME=	X11R6.7.0-src1
PKGNAME=	xorg-fontsEncodings-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Encoding fonts

BUILD_DEPENDS=	xorg-clients>=6.7.0:../../x11/xorg-clients

CONFLICTS=	XFree86-fontsEncodings-[0-9]*

NO_XFREE86_TARGETS=	# defined
CHECK_X11_TYPE=		# defined
XBUILD_DIRS=		fonts/encodings

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
