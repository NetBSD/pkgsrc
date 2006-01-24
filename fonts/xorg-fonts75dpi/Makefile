# $NetBSD: Makefile,v 1.9 2006/01/24 07:32:08 wiz Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fonts75dpi-${XORG_VER}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org 75dpi bitmap fonts

DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/75dpi
XINSTALL_DIRS=	fonts/bdf/75dpi
XEXTRACTS=	${XBUILD_DIRS}

.include "../../fonts/xorg-fontsEncodings/Makefile.common"
.include "../../mk/bsd.pkg.mk"
