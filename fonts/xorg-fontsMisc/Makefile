# $NetBSD: Makefile,v 1.7 2005/03/30 20:40:31 hira Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsMisc-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org miscellaneous bitmap fonts

BUILD_DEPENDS=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/misc
XINSTALL_DIRS=	fonts/bdf/misc
XEXTRACTS=	${XBUILD_DIRS} extras/fonts

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
