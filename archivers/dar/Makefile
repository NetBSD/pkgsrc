# $NetBSD: Makefile,v 1.11 2005/01/24 16:58:06 tv Exp $

DISTNAME=	dar-2.1.5
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--enable-examples
CONFIGURE_ARGS+=	--disable-upx

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
