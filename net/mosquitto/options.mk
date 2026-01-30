# $NetBSD: options.mk,v 1.4 2026/01/30 01:07:56 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mosquitto
PKG_SUPPORTED_OPTIONS=	tests
PKG_SUGGESTED_OPTIONS=	tests

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mtests)
CMAKE_CONFIGURE_ARGS+=	-DWITH_TESTS=ON

DEPENDS+=		microsocks-[0-9]*:../../net/microsocks
.include "../../devel/cunit/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"

# find work/mosquitto-2.1.0rc1/ -name \*.py|xargs egrep python3|awk -F: '{print $1}' | sed -e s,work/mosquitto-2.1.0rc1/,,|sort|while read f; do echo "REPLACE_PYTHON+=    $f"; done > replace-python.mk
.include "replace-python.mk"
.include "../../lang/python/application.mk"

TEST_TARGET=		test

retest-verbose:
	cd ${WRKSRC}/${CMAKE_BUILD_DIR} && ctest --rerun-failed --output-on-failure
.else
CMAKE_CONFIGURE_ARGS+=	-DWITH_TESTS=OFF

TEST_TARGET=		failtest
.endif
