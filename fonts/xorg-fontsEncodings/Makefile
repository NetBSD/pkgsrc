# $NetBSD: Makefile,v 1.5 2004/09/21 17:38:52 xtraeme Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsEncodings-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Encoding fonts

BUILD_DEPENDS=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients

XBUILD_DIRS=	fonts/encodings

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
