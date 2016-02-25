# $NetBSD: Makefile,v 1.56 2016/02/25 14:42:56 jperkin Exp $

.include "dist.mk"

PKGNAME=	python27-${PY_DISTVERSION}
PKGREVISION=	1
CATEGORIES=	lang python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language
LICENSE=	python-software-foundation

DEPENDS=	mozilla-rootcerts>=1.0.20150804nb1:../../security/mozilla-rootcerts

CONFLICTS+=	python-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT=${CFLAGS:Q}
CONFIGURE_ARGS+=	--with-system-ffi
CONFIGURE_ARGS+=	--with-dbmliborder=ndbm:bdb
CONFIGURE_ENV+=		MKDIR_P=${MKDIR:Q}

PKGCONFIG_OVERRIDE+=	Misc/python.pc.in

LDFLAGS+=		-L${WRKSRC}

# $RANDOM usage there is fine
CHECK_PORTABILITY_SKIP=	Tools/faqwiz/move-faqwiz.sh

USE_LANGUAGES=		c c++

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

PY_VER_SUFFIX=		2.7

PLIST_SRC=	${.CURDIR}/../../lang/python27/PLIST.common
.if exists(${.CURDIR}/../../lang/python27/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python27/PLIST.${OPSYS}
.endif
PLIST_SRC+=	${.CURDIR}/../../lang/python27/PLIST.common_end

.if ${OPSYS} == "NetBSD"
.  if !defined(USE_DESTDIR) || empty(USE_DESTDIR:M[Yy][Ee][Ss])
PRIVILEGED_STAGES+=	clean
.  endif
# XXX work around a botched autoconf check which ignores libintl
CONFIGURE_ENV+=		ac_cv_func_bind_textdomain_codeset=yes
.endif

.if ${OPSYS} == "Cygwin" || ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
PY_PLATNAME=	${LOWER_OPSYS}
USE_TOOLS+=	gmake
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.elif ${OPSYS} == "HPUX"
PY_PLATNAME=	hp-ux11
.elif ${OPSYS} == "Linux"
PY_PLATNAME=	linux2
.elif ${OS_VARIANT} == "SCOOSR5"
PY_PLATNAME=	sco_sv3
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

.if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "sparc64") || \
    (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "powerpc64") || \
    (defined(ABI) && ${ABI} == "64")
IS_64BIT_PLATFORM?=	yes
.else
IS_64BIT_PLATFORM?=	no
.endif

# the dl module isn't built for 64 bit archs
PLIST_VARS+=	dl
.if empty(IS_64BIT_PLATFORM:M[yY][eE][sS])
PLIST.dl=	yes
.endif

# setup.py causes some modules to be built if the platform is *not* 64bit.
PLIST_VARS+=	extra-so
.if !empty(IS_64BIT_PLATFORM:M[nN][oO])
PLIST.extra-so=	yes
.endif

# For Xcode 5 we need to search the SDK path for headers, otherwise certain
# modules will not be built.
.if ${OPSYS} == "Darwin" && exists(${OSX_SDK_PATH}/usr/include)
CFLAGS+=		-I${OSX_SDK_PATH}/usr/include
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
.  if ${OPSYS} == "MirBSD"
# neither nis nor no-nis
.  elif ${OPSYS} != "NetBSD" || exists(/usr/bin/ypcat)
PLIST.nis=	yes
.  else
PLIST.no-nis=	yes
.  endif
.endif

.include "../../mk/bdb.buildlink3.mk"
MAKE_ENV+=	PY_BDB_TYPE=${BDB_TYPE}
.if empty(BDB_LIBS)
BUILDLINK_TRANSFORM+=	rm:-ldb
.endif
CFLAGS+=	-DHAVE_DB_185_H

# configure complains about buggy getaddrinfo()
CONFIGURE_ARGS.OSF1+=	--disable-ipv6

.if defined(BUILDLINK_TRANSFORM)
MAKE_ENV+=	PY_BDB_TRANSFORM=${BUILDLINK_TRANSFORM:Q}
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

TEST_TARGET=	test
INSTALL_TARGET=	altinstall

REPLACE_INTERPRETER+=	py27
REPLACE.py27.old=	.*python[^ ]*
REPLACE.py27.new=	${PREFIX}/bin/python${PY_VER_SUFFIX}
REPLACE_FILES.py27=	Lib/*.py Lib/*/*.py Lib/*/*/*.py
REPLACE_FILES.py27+=	Lib/*/*/*/*.py

SUBST_CLASSES+=		libffi
SUBST_MESSAGE.libffi=	Fixing libffi include path on Darwin.
SUBST_STAGE.libffi=	pre-configure
SUBST_FILES.libffi=	setup.py
SUBST_SED.libffi=	-e 's,/usr/include/ffi,${BUILDLINK_PREFIX.libffi}/include,'

SUBST_CLASSES+=		findlib
SUBST_MESSAGE.findlib=	Fixing find_library_file on Darwin.
SUBST_STAGE.findlib=	pre-configure
SUBST_FILES.findlib=	Lib/distutils/unixccompiler.py
SUBST_SED.findlib=	-e 's,/usr/local,${PREFIX},'

SUBST_CLASSES+=		sslbase
SUBST_MESSAGE.sslbase=	Fixing find-file for openssl with SSLBASE.
SUBST_STAGE.sslbase=	pre-configure
SUBST_FILES.sslbase=	setup.py
SUBST_VARS.sslbase=	SSLBASE

SUBST_CLASSES+=		cacert
SUBST_MESSAGE.cacert=	Configuring location of default CA certificate file.
SUBST_STAGE.cacert=	pre-configure
SUBST_FILES.cacert=	Modules/_ssl.c
SUBST_SED.cacert=	-e 's,@PREFIX@,${PREFIX},'

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

BUILDLINK_DEPMETHOD.readline=		build

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
