# $NetBSD: Makefile,v 1.11 2006/02/12 15:29:17 xtraeme Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fonts100dpi-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org 100dpi bitmap fonts

DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/100dpi
XINSTALL_DIRS=	fonts/bdf/100dpi
XEXTRACTS=	${XBUILD_DIRS} fonts/bdf/75dpi/Imakefile.inc

.include "../../fonts/xorg-fontsEncodings/Makefile.common"
.include "../../mk/bsd.pkg.mk"
