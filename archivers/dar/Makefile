# $NetBSD: Makefile,v 1.17 2005/12/05 20:20:10 rillig Exp $

DISTNAME=	dar-2.2.2
PKGREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--enable-examples
CONFIGURE_ARGS+=	--disable-upx

# Needed for getopt() with SunPro
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
