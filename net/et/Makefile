# $NetBSD$

GITHUB_PROJECT=	EternalTerminal
GITHUB_TAG=	et-v${PKGVERSION_NOREV}

DISTNAME=	et-6.1.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=MisterTea/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MisterTea/EternalTerminal/
COMMENT=	Remote shell to automatically reconnect
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/EternalTerminal-et-v6.1.11
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

PKGCONFIG_OVERRIDE+=	external_imported/Catch2/CMake/catch2.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/UniversalStacktrace/external/Catch2/CMake/catch2.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/json/benchmarks/thirdparty/benchmark/cmake/benchmark.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/json/cmake/pkg-config.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/msgpack-c/msgpack.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/sentry-native/external/breakpad/breakpad-client.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/sentry-native/external/breakpad/breakpad.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/bzip2/bzip2.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/libvpx/vpx.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/openssl/openssl.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/sqlite3/sqlite3.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/szip/szip.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8_libbase.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8_libplatform.pc.in
PKGCONFIG_OVERRIDE+=	external_imported/vcpkg/ports/v8/v8_monolith.pc.in

.include "../../mk/bsd.pkg.mk"
