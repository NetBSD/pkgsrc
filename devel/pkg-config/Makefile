# $NetBSD: Makefile,v 1.29 2013/09/28 06:32:08 obache Exp $

DISTNAME=	pkg-config-0.28
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pkgconfig.freedesktop.org/
COMMENT=	System for managing library compile/link flags
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-internal-glib
CONFIGURE_ARGS+=	--disable-host-tool
CONFIGURE_ARGS+=	--disable-maintainer-mode

# old name of the package
CONFLICTS=		pkgconfig-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=	--cache-file=/dev/null
.endif

.if ${OPSYS} == "NetBSD"
post-configure:
	cd ${WRKSRC}/glib; \
	${GREP} -v HAVE_DTRACE config.h >config.h.new; \
	${MV} config.h.new config.h
.endif

.if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--disable-dtrace
.endif

CONFIGURE_ARGS+=	${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
CONFIGURE_ARGS.gnu-iconv=	--with-libiconv=gnu

PKGCONFIG_EXTRA_PATHS=	# empty

.if ${LOCALBASE} != ${X11BASE}
PKGCONFIG_EXTRA_PATHS+=	${X11BASE}/lib/pkgconfig
.endif

.if ${LOCALBASE} != "/usr"
PKGCONFIG_EXTRA_PATHS+=	/usr/lib/pkgconfig
.endif

.if !empty(PKGCONFIG_EXTRA_PATHS)
# First part of the value is taken from configure.in
CONFIGURE_ARGS+=	--with-pc-path='$${libdir}/pkgconfig:$${datadir}/pkgconfig:${PKGCONFIG_EXTRA_PATHS:ts::Q}'
.endif

# needed for fifth test case
BUILDLINK_PASSTHRU_DIRS+=	/private-dep /public-dep /requires-test
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
