# $NetBSD: Makefile,v 1.42 2003/09/21 21:47:11 wiz Exp $
#

DISTNAME=	libwmf-0.2.8
PKGREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://wvware.sourceforge.net/libwmf.html
COMMENT=	Library for reading and converting WMF (Windows Meta Files)

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--disable-gd
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/libwmf

post-install:
	${RMDIR} ${PREFIX}/include/libwmf/gd

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
