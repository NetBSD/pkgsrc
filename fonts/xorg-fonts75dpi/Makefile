# $NetBSD: Makefile,v 1.5 2004/07/30 23:25:08 xtraeme Exp $

DISTNAME=	X11R6.7.0-src1
PKGNAME=	xorg-fonts75dpi-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org 75dpi bitmap fonts

BUILD_DEPENDS=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/75dpi
XINSTALL_DIRS=	fonts/bdf/75dpi

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
