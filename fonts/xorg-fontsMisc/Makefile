# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 04:58:31 xtraeme Exp $

DISTNAME=	X11R6.7.0-src1
PKGNAME=	xorg-fontsMisc-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org miscellaneous bitmap fonts

BUILD_DEPENDS=	xorg-clients>=6.7.0:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=6.7.0:../../x11/xorgs-fontsEncodings

CONFLICTS=	XFree86-fontsMisc-[0-9]*

NO_XFREE86_TARGETS=	# defined
CHECK_X11_TYPE=		# defined
XBUILD_DIRS=		fonts/encodings fonts/bdf/misc
XINSTALL_DIRS=		fonts/bdf/misc

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
