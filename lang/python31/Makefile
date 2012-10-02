# $NetBSD: Makefile,v 1.13 2012/10/02 20:11:51 asau Exp $

.include "dist.mk"

PKGNAME=	python31-${PY_DISTVERSION}
PKGREVISION=	1
CATEGORIES=	lang python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

LICENSE=	python-software-foundation

CONFLICTS+=	python-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-system-ffi

LDFLAGS+=		-L${WRKSRC}

# $RANDOM usage there is fine
CHECK_PORTABILITY_SKIP=	Tools/faqwiz/move-faqwiz.sh
# ?
CHECK_PORTABILITY_SKIP+=	Mac/BuildScript/scripts/postflight.patch-profile

USE_LANGUAGES=		c c++

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

.include "../../mk/bsd.prefs.mk"

# fdatasync()
LIBS.SunOS+=		-lrt

PY_VER_SUFFIX=		3.1

PLIST_SRC=	${.CURDIR}/../../lang/python31/PLIST.common
.if exists(${.CURDIR}/../../lang/python31/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python31/PLIST.${OPSYS}
.endif
PLIST_SRC+=	${.CURDIR}/../../lang/python31/PLIST.common_end

.if ${OPSYS} == "NetBSD"
PRIVILEGED_STAGES+=	clean
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
PY_PLATNAME=	${LOWER_OPSYS}
USE_TOOLS+=	gmake
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.elif ${OPSYS} == "HPUX"
PY_PLATNAME=	hp-ux11
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

PLIST_VARS+=   linux2
.if ${PY_PLATNAME} == "linux2"
PLIST.linux2=  yes
.endif

.if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "amd64") || \
    (${MACHINE_ARCH} == "sparc64") || (${MACHINE_ARCH} == "x86_64") || \
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

# builds additional modules if OpenSSL < 0.9.8
PLIST_VARS+=		openssl097
CHECK_BUILTIN.openssl:=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=	no
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS]) && \
    !empty(BUILTIN_PKG.openssl:Mopenssl-0.9.[67]*)
PLIST.openssl097=	yes
.endif

# setup.py causes some modules to be built if the platform is *not* 64bit.
PLIST_VARS+=	extra-so
.if !empty(IS_64BIT_PLATFORM:M[nN][oO])
PLIST.extra-so=	yes
.endif

# ossaudiodev is only available on x86 for the following platforms
PLIST_VARS+=	oss
.if (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64") && \
    (${PY_PLATNAME} == "linux2" || ${OPSYS} == "FreeBSD")
PLIST.oss=	yes
.endif

# Make sure python modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

PLIST_VARS+=	bsddb dll nis no-nis
.if ${OPSYS} == "IRIX"
.  if ${ABI} == "64"
PLIST.no-nis=	yes
.  else
PLIST.nis=	yes
.  endif
.else
.  include "../../mk/bdb.buildlink3.mk"
MAKE_ENV+=	PY_BDB_TYPE=${BDB_TYPE}
MAKE_ENV+=	PY_BDB_INCDIRS=${BUILDLINK_INCDIRS.${BDB_TYPE}:S,^,${BDBBASE}/,:Q}
MAKE_ENV+=	PY_BDB_LIBDIRS=${BDBBASE}/lib
PLIST.bsddb=	yes
PLIST.dll=	yes
.  if ${OPSYS} != "NetBSD" || exists(/usr/bin/ypcat)
PLIST.nis=	yes
.  else
PLIST.no-nis=	yes
.  endif
.endif

.if defined(BUILDLINK_TRANSFORM)
MAKE_ENV+=	PY_BDB_TRANSFORM=${BUILDLINK_TRANSFORM:Q}
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

PRINT_PLIST_AWK+=	{ gsub(/${PY_PLATNAME}/, "$${PY_PLATNAME}") }
PRINT_PLIST_AWK+=	{ gsub(/python${PY_VER_SUFFIX}/, \
				"python$${PY_VER_SUFFIX}") }

TEST_TARGET=	test
INSTALL_TARGET=	altinstall

REPLACE_INTERPRETER+=	py31
REPLACE.py31.old=	.*python[^ ]*
REPLACE.py31.new=	${PREFIX}/bin/python${PY_VER_SUFFIX}
REPLACE_FILES.py31=	Lib/*.py Lib/*/*.py Lib/*/*/*.py

SUBST_CLASSES+=		findlib
SUBST_MESSAGE.findlib=	Fixing find_library_file on Darwin.
SUBST_STAGE.findlib=	pre-configure
SUBST_FILES.findlib=	Lib/distutils/unixccompiler.py
SUBST_SED.findlib=	-e 's,/usr/local,${PREFIX},'

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc3 ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}
	${MV} ${WRKSRC}/Tools/scripts/2to3 ${WRKSRC}/Tools/scripts/2to3-${PY_VER_SUFFIX}

.if ${OPSYS} == "HPUX"
post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython3.1.sl \
		${DESTDIR}${PREFIX}/lib/libpython3.1.sl.1.0
.endif

USE_GNU_READLINE=			yes
BUILDLINK_DEPMETHOD.readline=		build

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
