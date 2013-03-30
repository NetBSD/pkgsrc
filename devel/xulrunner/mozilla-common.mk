# $NetBSD: mozilla-common.mk,v 1.46 2013/03/30 20:46:29 tron Exp $
#
# common Makefile fragment for mozilla packages based on gecko 2.0.
#
# used by devel/xulrunner/Makefile
# used by mail/thunderbird/Makefile
# used by www/firefox/Makefile
# used by www/seamonkey/Makefile

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config perl gmake autoconf213 unzip zip
USE_LANGUAGES+=		c99 c++
UNLIMIT_RESOURCES+=	datasize

.include "../../mk/bsd.prefs.mk"
# gcc45-4.5.3 of lang/gcc45 does not generate proper binary,
# but gcc 4.5.4 of NetBSD 7 generates working binary.
.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
GCC_REQD+=		4.6
.else
GCC_REQD+=		4.5
.endif

CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=${MOZILLA_DIR}security/nss/tests/multinit/multinit.sh
CHECK_INTERPRETER_SKIP+=lib/xulrunner-sdk/sdk/bin/xpt.py

CONFIGURE_ARGS+=	--disable-tests --disable-pedantic
CONFIGURE_ARGS+=	--enable-crypto
CONFIGURE_ARGS+=	--enable-optimize=-O2 --with-pthreads
CONFIGURE_ARGS+=	--disable-javaxpcom
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-svg --enable-mathml
CONFIGURE_ARGS+=	--enable-system-cairo
CONFIGURE_ARGS+=	--enable-system-pixman
CONFIGURE_ARGS+=	--with-system-libvpx
CONFIGURE_ARGS+=	--enable-system-hunspell
CONFIGURE_ARGS+=	--enable-system-ffi
CONFIGURE_ARGS+=	--with-system-nss
CONFIGURE_ARGS+=	--with-system-nspr
## xulrunner-18.0 or later really requires libjpeg-turbo
#CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib --with-system-bz2
CONFIGURE_ARGS+=	--with-system-libevent=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--enable-system-sqlite
CONFIGURE_ARGS+=	--disable-crashreporter
CONFIGURE_ARGS+=	--disable-libnotify
CONFIGURE_ARGS+=	--disable-necko-wifi
CONFIGURE_ARGS+=	--enable-chrome-format=flat

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		${MOZILLA_DIR}xpcom/build/nsXPCOMPrivate.h
SUBST_FILES.fix-paths+=		${MOZILLA_DIR}xpcom/io/nsAppFileLocationProvider.cpp
SUBST_SED.fix-paths+=		-e 's,/usr/lib/mozilla/plugins,${PREFIX}/lib/netscape/plugins,g'

CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.guess
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}nsprpub/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=		${MOZILLA_DIR}/js/ctypes/libffi/config.sub

PYTHON_FOR_BUILD_ONLY=		yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python.
SUBST_FILES.python+=	media/webrtc/trunk/build/common.gypi
SUBST_SED.python+=	-e 's,<!(python,<!(${PYTHONBIN},'

# When MACHINAE_ARCH == "arm", libjpeg-turbo should be enabled.
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
BUILD_DEPENDS+=		yasm>=1.1.0:../../devel/yasm
CONFIGURE_ARGS+=	--enable-libjpeg-turbo
.else
CONFIGURE_ARGS+=	--diable-libjpeg-turbo
.endif

#
# pysqlite2 is used by xulrunner's Python virtualenv.  If pysqlite2 isn't
# installed at build time it will attempt to download it instead, so the
# problem is stealthy in a networked environment, and obvious in an
# offline environment.
#
BUILD_DEPENDS+=	${PYPKGPREFIX}-sqlite2-[0-9]*:../../databases/py-sqlite2

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# The configure test for __thread succeeds, but later we end up with:
# dist/bin/libxul.so: undefined reference to `__tls_get_addr'
CONFIGURE_ENV+=	ac_cv_thread_keyword=no
.endif

.if ${OPSYS} == "SunOS"
# native libbz2.so hides BZ2_crc32Table
PREFER.bzip2?=	pkgsrc
.endif

.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.7.14.1
CONFIGURE_ENV+=	ac_cv_sqlite_secure_delete=yes	# c.f. patches/patch-al
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.9.4
.include "../../devel/nspr/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=	nss>=3.14.1
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
## xulrunner-18.0 or later really requires libjpeg-turbo
#.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.10.2nb4
.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.18.3nb1
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
