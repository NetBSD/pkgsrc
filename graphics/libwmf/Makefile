# $NetBSD: Makefile,v 1.48 2004/04/25 04:52:57 minskim Exp $
#

DISTNAME=	libwmf-0.2.8.2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=	kei@NetBSD.org
HOMEPAGE=	http://wvware.sourceforge.net/libwmf.html
COMMENT=	Library for reading and converting WMF (Windows Meta Files)

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--disable-gd
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/html/libwmf

post-install:
	${RMDIR} ${PREFIX}/include/libwmf/gd

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
