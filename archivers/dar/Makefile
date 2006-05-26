# $NetBSD: Makefile,v 1.21 2006/05/26 10:10:08 adam Exp $

DISTNAME=	dar-2.3.0
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dar.linux.free.fr/
COMMENT=	Disk archiver

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dar-static
CONFIGURE_ARGS+=	--disable-nodump-flag
CONFIGURE_ARGS+=	--disable-upx
CONFIGURE_ARGS+=	--enable-examples

PKGCONFIG_OVERRIDE=	src/libdar/libdar.pc.tmpl.in
UNLIMIT_RESOURCES=	datasize

# Needed for getopt() with SunPro
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
