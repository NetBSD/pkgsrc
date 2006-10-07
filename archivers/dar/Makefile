# $NetBSD: Makefile,v 1.23 2006/10/07 07:10:29 obache Exp $

DISTNAME=	dar-2.3.1
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

PKG_OPTIONS_VAR=	PKG_OPTIONS.dar
PKG_SUPPORTED_OPTIONS=	dar-int32 dar-int64
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# Dar is built by default with an arbitrary-size-integer library for
# managing all file length/timestamp details.  If 32-bit or 64-bit
# integers (with overflow protection) are sufficient for requirements,
# the following options can significantly reduce the run-time memory
# and CPU overheads of Dar.
.if !empty(PKG_OPTIONS:Mdar-int64)
CONFIGURE_ARGS+=	--enable-mode=64
.elif !empty(PKG_OPTIONS:Mdar-int32)
CONFIGURE_ARGS+=	--enable-mode=32
.endif

PKGCONFIG_OVERRIDE=	src/libdar/libdar.pc.tmpl.in
UNLIMIT_RESOURCES=	datasize

# Needed for getopt() with SunPro
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
