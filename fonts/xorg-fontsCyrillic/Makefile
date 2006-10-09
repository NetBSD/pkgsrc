# $NetBSD: Makefile,v 1.14 2006/10/09 12:52:35 joerg Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsCyrillic-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Cyrillic bitmap fonts

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	imake

DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/bdf/cyrillic
XINSTALL_DIRS=	fonts/bdf/cyrillic
XEXTRACTS=	${XBUILD_DIRS}

FONTS_DIRS.x11+=	${X11ROOT_PREFIX}/lib/X11/fonts/cyrillic

.include "../../fonts/xorg-fontsEncodings/Makefile.common"
.include "../../mk/bsd.pkg.mk"
