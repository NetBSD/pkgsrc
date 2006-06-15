# $NetBSD: Makefile,v 1.11 2006/06/15 15:20:20 joerg Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsEncodings-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Encoding fonts

XBUILD_DIRS=	fonts/encodings
XEXTRACTS=	${XBUILD_DIRS}

USE_TOOLS+=	imake

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
