# $NetBSD: Makefile,v 1.6 2005/03/30 20:40:31 hira Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsEncodings-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Encoding fonts

BUILD_DEPENDS=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients

XBUILD_DIRS=	fonts/encodings
XEXTRACTS=	${XBUILD_DIRS}

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
