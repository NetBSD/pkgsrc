# $NetBSD: Makefile,v 1.116 2024/05/29 16:33:16 adam Exp $

.include "dist.mk"

PKGNAME=	python27-${PY_DISTVERSION}
PKGREVISION=	16
CATEGORIES=	lang python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language
LICENSE=	python-software-foundation

DEPENDS=	mozilla-rootcerts>=1.0.20150804nb1:../../security/mozilla-rootcerts

CONFLICTS+=	python-[0-9]*
CONFLICTS+=	py27-cElementTree-[0-9]*
CONFLICTS+=	py27-curses-[0-9]*
CONFLICTS+=	py27-cursespanel-[0-9]*
CONFLICTS+=	py27-expat-[0-9]*
CONFLICTS+=	py27-readline-[0-9]*
CONFLICTS+=	py27-sqlite3-[0-9]*
SUPERSEDES+=	py27-cElementTree-[0-9]*
SUPERSEDES+=	py27-curses-[0-9]*
SUPERSEDES+=	py27-cursespanel-[0-9]*
SUPERSEDES+=	py27-expat-[0-9]*
SUPERSEDES+=	py27-readline-[0-9]*
SUPERSEDES+=	py27-sqlite3-[0-9]*

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-dbmliborder=ndbm:bdb
CONFIGURE_ARGS+=	--with-system-expat
CONFIGURE_ARGS+=	--with-system-ffi
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	PKG_CONFIG=${PREFIX}/bin/pkg-config
CONFIGURE_ENV+=		MKDIR_P=${MKDIR:Q}
CONFIGURE_ENV+=		OPT=${CFLAGS:M*:Q}
PKGCONFIG_OVERRIDE+=	Misc/python.pc.in

LDFLAGS+=		-L${WRKSRC}

# $RANDOM usage there is fine
CHECK_PORTABILITY_SKIP=	Tools/faqwiz/move-faqwiz.sh

# NetBSD-8 curses has enough support for py-curses
USE_CURSES=		getsyx wide
# But we build as ncurses still to get the full feature set easily
FAKE_NCURSES=		yes

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

.include "../../mk/compiler.mk"

# Clang needs -fwrapv
.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-fwrapv
.endif

.include "../../mk/bsd.prefs.mk"

# fdatasync()
LIBS.SunOS+=		-lrt
.if ${OPSYS} == "SunOS" && ${OPSYS_VERSION} < 051100
SUBST_CLASSES+=		setup
SUBST_MESSAGE.setup=	Replacing crypt with crypt_i
SUBST_STAGE.setup=	pre-configure
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e "s,\([ \[]\)'crypt',\\1'crypt_i',"
.endif

PY_VER_SUFFIX=		2.7

.if ${OPSYS} == "NetBSD"
# XXX work around a botched autoconf check which ignores libintl
CONFIGURE_ENV+=		ac_cv_func_bind_textdomain_codeset=yes
.endif

.if ${OPSYS} == "Cygwin" || ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
USE_TOOLS+=	gmake
.endif

.include "platname.mk"
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
    (defined(ABI) && ${ABI} == "64")
IS_64BIT_PLATFORM?=	yes
.else
IS_64BIT_PLATFORM?=	no
.endif

PLIST_VARS+=	dl dll extra-so nis qt

# the dl module isn't built for 64 bit archs
.if empty(IS_64BIT_PLATFORM:M[yY][eE][sS])
PLIST.dl=	yes
.endif

# setup.py causes some modules to be built if the platform is *not* 64bit.
.if !empty(IS_64BIT_PLATFORM:M[nN][oO])
PLIST.extra-so=	yes
.endif

# For Xcode 5 we need to search the SDK path for headers, otherwise certain
# modules will not be built.
.if ${OPSYS} == "Darwin"
.  if exists(${OSX_SDK_PATH}/usr/include)
CFLAGS+=		-I${OSX_SDK_PATH:Q}/usr/include
SUBST_CLASSES+=		sdkpath
SUBST_STAGE.sdkpath=	pre-configure
SUBST_FILES.sdkpath=	Lib/distutils/unixccompiler.py
SUBST_VARS.sdkpath=	OSX_SDK_PATH
.  endif
.  if exists(${OSX_SDK_PATH}/System/Library/Frameworks/QuickTime.framework)
PLIST.qt=		yes
.  endif
.endif

.if ${OPSYS} != "IRIX"
PLIST.dll=	yes
.endif

.for incdir in ${_OPSYS_INCLUDE_DIRS}
.  if (exists(${incdir}/rpc/rpc.h) || exists(${incdir}/tirpc/rpc/rpc.h))
HAVE_RPC_H=	yes
.  endif
.  if (exists(${incdir}/rpcsvc/yp_prot.h) || exists(${incdir}/nsl/rpcsvc/yp_prot.h))
HAVE_YP_PROT_H=	yes
.  endif
.endfor
.if (${HAVE_RPC_H:Uno} == yes && ${HAVE_YP_PROT_H:Uno} == yes)
PLIST.nis=	yes
.endif

# configure complains about buggy getaddrinfo()
CONFIGURE_ARGS.OSF1+=	--disable-ipv6

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

TEST_TARGET=	test
INSTALL_TARGET=	altinstall

REPLACE_INTERPRETER+=	py27
REPLACE.py27.old=	.*python[^ ]*
REPLACE.py27.new=	${PREFIX}/bin/python${PY_VER_SUFFIX}
REPLACE_FILES.py27=	Lib/UserString.py
REPLACE_FILES.py27+=	Lib/base64.py
REPLACE_FILES.py27+=	Lib/cProfile.py
REPLACE_FILES.py27+=	Lib/cgi.py
REPLACE_FILES.py27+=	Lib/encodings/rot_13.py
REPLACE_FILES.py27+=	Lib/idlelib/PyShell.py
REPLACE_FILES.py27+=	Lib/keyword.py
REPLACE_FILES.py27+=	Lib/lib2to3/pgen2/token.py
REPLACE_FILES.py27+=	Lib/lib2to3/tests/data/different_encoding.py
REPLACE_FILES.py27+=	Lib/lib2to3/tests/data/false_encoding.py
REPLACE_FILES.py27+=	Lib/lib2to3/tests/pytree_idempotency.py
REPLACE_FILES.py27+=	Lib/mimify.py
REPLACE_FILES.py27+=	Lib/pdb.py
REPLACE_FILES.py27+=	Lib/plat-mac/appletrunner.py
REPLACE_FILES.py27+=	Lib/plat-mac/bundlebuilder.py
REPLACE_FILES.py27+=	Lib/platform.py
REPLACE_FILES.py27+=	Lib/profile.py
REPLACE_FILES.py27+=	Lib/pydoc.py
REPLACE_FILES.py27+=	Lib/quopri.py
REPLACE_FILES.py27+=	Lib/smtpd.py
REPLACE_FILES.py27+=	Lib/smtplib.py
REPLACE_FILES.py27+=	Lib/symbol.py
REPLACE_FILES.py27+=	Lib/tabnanny.py
REPLACE_FILES.py27+=	Lib/test/bisect_cmd.py
REPLACE_FILES.py27+=	Lib/test/curses_tests.py
REPLACE_FILES.py27+=	Lib/test/re_tests.py
REPLACE_FILES.py27+=	Lib/test/pystone.py
REPLACE_FILES.py27+=	Lib/test/regrtest.py
REPLACE_FILES.py27+=	Lib/timeit.py
REPLACE_FILES.py27+=	Lib/trace.py
REPLACE_FILES.py27+=	Lib/uu.py
REPLACE_FILES.py27+=	Lib/webbrowser.py

SUBST_CLASSES+=		libffi
SUBST_MESSAGE.libffi=	Fixing libffi include path on Darwin.
SUBST_STAGE.libffi=	pre-configure
SUBST_FILES.libffi=	setup.py
SUBST_SED.libffi=	-e 's,/usr/include/ffi,${BUILDLINK_PREFIX.libffi}/include,'

# XXX: It might be needed to add manually more paths like ${PREFIX}/qt5/lib
# Test: python -c 'from ctypes.util import find_library; print(find_library("ffi"));'
SUBST_CLASSES+=		findlib
SUBST_MESSAGE.findlib=	Fixing find_library().
SUBST_STAGE.findlib=	pre-configure
SUBST_FILES.findlib=	Lib/ctypes/macholib/dyld.py
SUBST_FILES.findlib+=	Lib/ctypes/util.py
SUBST_FILES.findlib+=	Lib/distutils/unixccompiler.py
SUBST_SED.findlib=	-e 's,/usr/local,${PREFIX},'
SUBST_SED.findlib+=	-e 's!\(-Wl,-t -o\)!${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib \1!'
SUBST_NOOP_OK.findlib=	yes

SUBST_CLASSES+=			pkgversion
SUBST_STAGE.pkgversion=		pre-configure
SUBST_FILES.pkgversion=		Lib/lib2to3/pgen2/driver.py
SUBST_FILES.pkgversion+=	Lib/distutils/command/install_egg_info.py
SUBST_VARS.pkgversion=		PKGVERSION_NOREV

SUBST_CLASSES+=		urllib
SUBST_MESSAGE.urllib=	Fixing path to urllib.cfg.
SUBST_STAGE.urllib=	pre-configure
SUBST_FILES.urllib=	Lib/urlparse.py
SUBST_VARS.urllib=	PKG_SYSCONFDIR

.include "options.mk"

SUBST_CLASSES+=		sslbase
SUBST_MESSAGE.sslbase=	Fixing find-file for openssl with SSLBASE.
SUBST_STAGE.sslbase=	pre-configure
SUBST_FILES.sslbase=	setup.py
SUBST_VARS.sslbase=	SSLBASE

SUBST_CLASSES+=		cacert
SUBST_MESSAGE.cacert=	Configuring location of default CA certificate file.
SUBST_STAGE.cacert=	pre-configure
SUBST_FILES.cacert=	Modules/_ssl.c
SUBST_VARS.cacert=	PREFIX

post-extract:
	${LN} -s ${WRKSRC}/Lib/smtpd.py ${WRKSRC}/Tools/scripts/smtpd${PY_VER_SUFFIX}.py
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}
	${MV} ${WRKSRC}/Tools/scripts/2to3 ${WRKSRC}/Tools/scripts/2to3-${PY_VER_SUFFIX}

.if ${OPSYS} == "HPUX"
post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython2.7.sl \
		${DESTDIR}${PREFIX}/lib/libpython2.7.sl.1.0
.endif

.if ${OS_VARIANT} == "SCOOSR5"
# SCO OpenServer 5.0.7/3.2 has no socklen_t in system headers, but has in
# GNU pth's header. It should be used in this case.
CONFIGURE_ENV+=		ac_cv_type_socklen_t=yes
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
