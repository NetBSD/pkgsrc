# $NetBSD: Makefile,v 1.4 2012/10/02 20:11:51 asau Exp $

.include "dist.mk"

PKGNAME=	python32-${PY_DISTVERSION}
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
CONFIGURE_ARGS+=	--without-pymalloc

USE_LANGUAGES=		c c++

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.prefs.mk"

# fdatasync()
LIBS.SunOS+=		-lrt

PY_VER_SUFFIX=		3.2

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
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
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

# builds additional modules if OpenSSL < 0.9.8
PLIST_VARS+=		openssl097
CHECK_BUILTIN.openssl:=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=	no
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS]) && \
    !empty(BUILTIN_PKG.openssl:Mopenssl-0.9.[67]*)
PLIST.openssl097=	yes
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

REPLACE_INTERPRETER+=	py32
REPLACE.py32.old=	.*python[^ ]*
REPLACE.py32.new=	${PREFIX}/bin/python${PY_VER_SUFFIX}
REPLACE_FILES.py32=	Lib/*.py Lib/*/*.py Lib/*/*/*.py

.if ${OPSYS} == "HPUX"
post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython3.2.sl \
		${DESTDIR}${PREFIX}/lib/libpython3.2.sl.1.0
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
