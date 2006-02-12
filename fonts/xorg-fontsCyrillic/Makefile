# $NetBSD: Makefile,v 1.11 2006/02/12 15:29:18 xtraeme Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsCyrillic-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Cyrillic bitmap fonts

DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/cyrillic
XINSTALL_DIRS=	fonts/bdf/cyrillic
XEXTRACTS=	${XBUILD_DIRS}

.include "../../fonts/xorg-fontsEncodings/Makefile.common"
.include "../../mk/bsd.pkg.mk"
