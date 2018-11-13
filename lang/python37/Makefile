# $NetBSD: Makefile,v 1.3 2018/11/13 11:54:06 markd Exp $

.include "dist.mk"

PKGNAME=	python37-${PY_DISTVERSION}
CATEGORIES=	lang python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language
LICENSE=	python-software-foundation

CONFLICTS+=	python-[0-9]*

PLIST_AWK+=		-f ${PKGSRCDIR}/lang/python/plist-python.awk
PLIST_AWK_ENV+=		PYVERS=37
PRINT_PLIST_AWK+=	/^[^@]/ && /[^\/]+\.pyc$$/ {
PRINT_PLIST_AWK+=	sub(/__pycache__\//, "")
PRINT_PLIST_AWK+=	sub(/\.cpython-37/, "")}
PRINT_PLIST_AWK+=	/^[^@]/ && /[^\/]+\.opt-1.pyc$$/ {
PRINT_PLIST_AWK+=	sub(/.opt-[12].pyc$$/, ".pyo")}

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-system-ffi
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--without-ensurepip
CONFIGURE_ENV+=		OPT=${CFLAGS:M*:Q}
CONFIGURE_ENV+=		ac_cv_path_mkdir=${TOOLS_PATH.mkdir}
PKGCONFIG_OVERRIDE+=	Misc/python.pc.in

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

# http://bugs.python.org/issue13241
.if !empty(MACHINE_PLATFORM:MDarwin-10.*)
PKGSRC_COMPILER=	clang
PKG_CC=			clang
PKG_CXX=		clang++
.endif

# fdatasync()
LIBS.SunOS+=		-lrt

PY_VER_SUFFIX=		3.7

.if ${OPSYS} == "Darwin"
PY_PLATNAME=	${LOWER_OPSYS}
USE_TOOLS+=	gmake
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.elif ${OPSYS} == "HPUX"
PY_PLATNAME=	hp-ux11
.elif ${OPSYS} == "Linux"
PY_PLATNAME=	linux
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

# ossaudiodev is only available on x86 for the following platforms
PLIST_VARS+=	oss
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && \
    (${PY_PLATNAME} == "linux" || ${OPSYS} == "FreeBSD")
PLIST.oss=	yes
.endif

# For Xcode 5 and up, we need to search the SDK path for headers, otherwise
# certain modules will not be built.
.if ${OPSYS} == "Darwin" && exists(${OSX_SDK_PATH:Q}/usr/include)
CFLAGS+=		-I${OSX_SDK_PATH:Q}/usr/include
.endif

PLIST_VARS+=	dll nis no-nis
.if ${OPSYS} == "IRIX"
.  if ${ABI} == "64"
PLIST.no-nis=	yes
.  else
PLIST.nis=	yes
.  endif
.else
PLIST.dll=	yes
.  if ${OPSYS} != "NetBSD" || exists(/usr/bin/ypcat)
.    if "${OS_VARIANT}" != "chromeos"
PLIST.nis=	yes
.    endif
.  else
PLIST.no-nis=	yes
.  endif
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

PRINT_PLIST_AWK+=	{ gsub(/${PY_PLATNAME}/, "$${PY_PLATNAME}") }
PRINT_PLIST_AWK+=	{ gsub(/python${PY_VER_SUFFIX}/, \
				"python$${PY_VER_SUFFIX}") }

TEST_TARGET=	test
INSTALL_TARGET=	altinstall

REPLACE_INTERPRETER+=	py37
REPLACE.py37.old=	.*python[^ ]*
REPLACE.py37.new=	${PREFIX}/bin/python${PY_VER_SUFFIX}
REPLACE_FILES.py37+=	Lib/base64.py
REPLACE_FILES.py37+=	Lib/cProfile.py
REPLACE_FILES.py37+=	Lib/cgi.py
REPLACE_FILES.py37+=	Lib/encodings/rot_13.py
REPLACE_FILES.py37+=	Lib/idlelib/pyshell.py
REPLACE_FILES.py37+=	Lib/keyword.py
REPLACE_FILES.py37+=	Lib/lib2to3/pgen2/token.py
REPLACE_FILES.py37+=	Lib/lib2to3/tests/data/different_encoding.py
REPLACE_FILES.py37+=	Lib/lib2to3/tests/data/false_encoding.py
REPLACE_FILES.py37+=	Lib/lib2to3/tests/pytree_idempotency.py
REPLACE_FILES.py37+=	Lib/pdb.py
REPLACE_FILES.py37+=	Lib/platform.py
REPLACE_FILES.py37+=	Lib/profile.py
REPLACE_FILES.py37+=	Lib/pydoc.py
REPLACE_FILES.py37+=	Lib/quopri.py
REPLACE_FILES.py37+=	Lib/smtpd.py
REPLACE_FILES.py37+=	Lib/smtplib.py
REPLACE_FILES.py37+=	Lib/symbol.py
REPLACE_FILES.py37+=	Lib/tabnanny.py
REPLACE_FILES.py37+=	Lib/tarfile.py
REPLACE_FILES.py37+=	Lib/test/bisect.py
REPLACE_FILES.py37+=	Lib/test/crashers/recursive_call.py
REPLACE_FILES.py37+=	Lib/test/curses_tests.py
REPLACE_FILES.py37+=	Lib/test/re_tests.py
REPLACE_FILES.py37+=	Lib/test/regrtest.py
REPLACE_FILES.py37+=	Lib/timeit.py
REPLACE_FILES.py37+=	Lib/trace.py
REPLACE_FILES.py37+=	Lib/turtledemo/__main__.py
REPLACE_FILES.py37+=	Lib/turtledemo/bytedesign.py
REPLACE_FILES.py37+=	Lib/turtledemo/clock.py
REPLACE_FILES.py37+=	Lib/turtledemo/forest.py
REPLACE_FILES.py37+=	Lib/turtledemo/fractalcurves.py
REPLACE_FILES.py37+=	Lib/turtledemo/lindenmayer.py
REPLACE_FILES.py37+=	Lib/turtledemo/minimal_hanoi.py
REPLACE_FILES.py37+=	Lib/turtledemo/paint.py
REPLACE_FILES.py37+=	Lib/turtledemo/peace.py
REPLACE_FILES.py37+=	Lib/turtledemo/penrose.py
REPLACE_FILES.py37+=	Lib/turtledemo/planet_and_moon.py
REPLACE_FILES.py37+=	Lib/turtledemo/sorting_animate.py
REPLACE_FILES.py37+=	Lib/turtledemo/tree.py
REPLACE_FILES.py37+=	Lib/turtledemo/yinyang.py
REPLACE_FILES.py37+=	Lib/uu.py
REPLACE_FILES.py37+=	Lib/webbrowser.py

SUBST_CLASSES+=		findlib
SUBST_MESSAGE.findlib=	Fixing find_library_file on Darwin.
SUBST_STAGE.findlib=	pre-configure
SUBST_FILES.findlib=	Lib/distutils/unixccompiler.py
SUBST_SED.findlib=	-e 's,/usr/local,${PREFIX},'

# XXX: It might be needed to add manually more paths like ${PREFIX}/qt5/lib
# Testing:
# >>> from ctypes.util import find_library
# >>> find_library("m")
# 'libm.so.0'

SUBST_CLASSES+=		pfindlib
SUBST_MESSAGE.pfindlib=	Fixing find_library() on POSIX-like (excluding Darwin) systems.
SUBST_STAGE.pfindlib=	pre-configure
SUBST_FILES.pfindlib=	Lib/ctypes/util.py
SUBST_SED.pfindlib=	-e 's!\(-Wl,-t -o\)!${COMPILER_RPATH_FLAG}${PREFIX}/lib -L${PREFIX}/lib \1!'

.include "options.mk"

CHECK_INTERPRETER_SKIP=	lib/python${PY_VER_SUFFIX}/venv/scripts/posix/pydoc

# Avoid error: Cannot generate ./Include/opcode.h, python not found !
post-configure:
	touch ${WRKSRC}/Include/opcode.h

.if ${OPSYS} == "HPUX"
post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython3.7.sl \
		${DESTDIR}${PREFIX}/lib/libpython3.7.sl.1.0
.endif

BUILDLINK_DEPMETHOD.readline=		build

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0.2
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
