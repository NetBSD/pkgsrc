# $NetBSD: Makefile,v 1.5 2004/07/30 23:25:08 xtraeme Exp $

DISTNAME=	X11R6.7.0-src1
PKGNAME=	xorg-fontsCyrillic-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Cyrillic bitmap fonts

BUILD_DEPENDS=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/cyrillic
XINSTALL_DIRS=	fonts/bdf/cyrillic

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
