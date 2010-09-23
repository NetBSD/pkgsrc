# $NetBSD: Makefile,v 1.17 2010/09/23 07:07:46 adam Exp $

DISTNAME=	pkg-config-0.25
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
CONFIGURE_ARGS+=	--disable-threads

# old name of the package
CONFLICTS=		pkgconfig-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
.  if ${OS_VERSION:R} < 5
# configure checks but does not fail on warning
CONFIGURE_ENV+=		glib_cv_va_copy=no
.  endif
.endif

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=	--cache-file=/dev/null
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	glib_cv_sane_realloc=yes glib_cv_uscore=no
CONFIGURE_ARGS+=	glib_cv_rtldglobal_broken=no
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

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
