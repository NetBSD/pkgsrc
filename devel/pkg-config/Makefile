# $NetBSD: Makefile,v 1.22 2012/08/15 10:12:54 jperkin Exp $

DISTNAME=	pkg-config-0.27
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pkgconfig.freedesktop.org/
COMMENT=	System for managing library compile/link flags
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		msgfmt
CONFIGURE_ARGS+=	--with-internal-glib
# needed since it can't use pkg-config to find glib2...
#CONFIGURE_ARGS+=	GLIB_CFLAGS="-I${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0 -I${BUILDLINK_PREFIX.glib2}/lib/glib-2.0/include"
#CONFIGURE_ARGS+=	GLIB_LIBS="${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.glib2}/lib -L${BUILDLINK_PREFIX.glib2}/lib -lglib-2.0 -lintl"

# old name of the package
CONFLICTS=		pkgconfig-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=	--cache-file=/dev/null
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--with-libiconv=gnu
CONFIGURE_ARGS+=	--disable-dtrace
.endif

PKGCONFIG_EXTRA_PATHS=	# empty

.if ${LOCALBASE} != ${X11BASE}
PKGCONFIG_EXTRA_PATHS+=	${X11BASE}/lib/pkgconfig
.endif

.if ${LOCALBASE} != "/usr"
PKGCONFIG_EXTRA_PATHS+=	/usr/lib/pkgconfig
.endif

.if !empty(PKGCONFIG_EXTRA_PATHS)
# First part of the value is taken from configure.in
CONFIGURE_ARGS+=	--with-pc-path='$${libdir}/pkgconfig:$${datadir}/pkgconfig:${PKGCONFIG_EXTRA_PATHS:ts:}'
.endif

# needed for fifth test case
BUILDLINK_PASSTHRU_DIRS= /private-dep /public-dep /requires-test
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
