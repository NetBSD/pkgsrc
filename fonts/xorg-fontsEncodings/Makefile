# $NetBSD: Makefile,v 1.12 2006/10/09 12:52:35 joerg Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsEncodings-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Encoding fonts

PKG_DESTDIR_SUPPORT=	user-destdir

XBUILD_DIRS=	fonts/encodings
XEXTRACTS=	${XBUILD_DIRS}

USE_TOOLS+=	imake

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
