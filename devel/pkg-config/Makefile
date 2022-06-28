# $NetBSD: Makefile,v 1.43 2022/06/28 11:33:41 wiz Exp $

DISTNAME=	pkg-config-0.29.2
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://pkgconfig.freedesktop.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pkgconfig.freedesktop.org/
COMMENT=	System for managing library compile/link flags
LICENSE=	gnu-gpl-v2

TOOLS_BROKEN+=		perl
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-internal-glib
CONFIGURE_ARGS+=	--disable-host-tool
CONFIGURE_ARGS+=	--disable-maintainer-mode

# old name of the package
CONFLICTS=		pkgconfig-[0-9]*

.include "../../mk/bsd.prefs.mk"

# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS.IRIX+=	--cache-file=/dev/null

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386" && ${OPSYS_VERSION} < 060000
# Built-in GLib wants __sync_bool_compare_and_swap_4
CFLAGS+=		-march=i486
.  endif
post-configure:
	cd ${WRKSRC}/glib; \
	${GREP} -v HAVE_DTRACE config.h >config.h.new; \
	${MV} config.h.new config.h
.endif

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2 has no IPv6 support.
CONFIGURE_ENV+=		glib_cv_value_AF_INET6=yes
.endif

CONFIGURE_ARGS.SunOS+=	--disable-dtrace
CFLAGS.SunOS+=		-DENABLE_NLS # required due to __EXTENSIONS__

CONFIGURE_ARGS+=		${CONFIGURE_ARGS.${ICONV_TYPE}-iconv}
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
