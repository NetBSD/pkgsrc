# $NetBSD: Makefile,v 1.3 2026/01/07 08:47:37 wiz Exp $

DISTNAME=	bigloo-4.6a
PKGREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	https://www-sop.inria.fr/indes/fp/Bigloo/download/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://www-sop.inria.fr/indes/fp/Bigloo/
COMMENT=	Scheme development environment
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP+=	api-contribs/bigloo-with-dbus/configure

USE_LANGUAGES=	c c++
USE_TOOLS=	gmake autoconf automake pkg-config
GNU_CONFIGURE=	yes
INFO_FILES=	yes

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/bigloo/${PKGVERSION_NOREV}

CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--cpicflags="-fPIC"
CONFIGURE_ARGS+=	--ldflags=${LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--customgc=no
CONFIGURE_ARGS+=	--gccustominstall=skip
CONFIGURE_ARGS+=	--gclibdir=${PREFIX}/lib
CONFIGURE_ARGS+=	--gcincdir=${PREFIX}/include
CONFIGURE_ARGS+=	--customlibuv=no
CONFIGURE_ARGS+=	--disable-pcre
CONFIGURE_ARGS+=	--disable-pcre2
CONFIGURE_ARGS+=	--customunistring=no
CONFIGURE_ARGS+=	--disable-libbacktrace
CONFIGURE_ARGS+=	--native=yes
CONFIGURE_ARGS+=	--sharedcompiler=yes
CONFIGURE_ARGS+=	--sharedbde=yes
CONFIGURE_ARGS+=	--strip=no
CONFIGURE_ARGS+=	--enable-calendar
CONFIGURE_ARGS+=	--enable-crypto
CONFIGURE_ARGS+=	--enable-csv
CONFIGURE_ARGS+=	--enable-libuv
CONFIGURE_ARGS+=	--enable-mail
CONFIGURE_ARGS+=	--enable-multimedia
CONFIGURE_ARGS+=	--enable-openpgp
CONFIGURE_ARGS+=	--enable-packrat
CONFIGURE_ARGS+=	--enable-phone
CONFIGURE_ARGS+=	--enable-pkgcomp
CONFIGURE_ARGS+=	--enable-pkglib
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-sqlite
CONFIGURE_ARGS+=	--enable-srfi1
CONFIGURE_ARGS+=	--enable-srfi18
CONFIGURE_ARGS+=	--enable-ssl
CONFIGURE_ARGS+=	--enable-text
CONFIGURE_ARGS+=	--enable-upnp
CONFIGURE_ARGS+=	--enable-web
# unsure how these APIs work or if they're useful
CONFIGURE_ARGS+=	--disable-gstreamer
CONFIGURE_ARGS+=	--disable-avahi

BUILD_TARGET=	boot
INSTALL_TARGET=	install

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/libuv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=     opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
