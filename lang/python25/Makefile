# $NetBSD: Makefile,v 1.41 2012/09/15 10:05:20 obache Exp $

.include "dist.mk"

PKGNAME=	python25-${PY_DISTVERSION}
PKGREVISION=	3
CATEGORIES=	lang python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	python-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--with-system-ffi

LDFLAGS+=		-L${WRKSRC}

USE_LANGUAGES=		c c++

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

.include "../../mk/bsd.prefs.mk"

# fdatasync()
LIBS.SunOS+=		-lrt

PY_VER_SUFFIX=		2.5

PLIST_SRC=	${.CURDIR}/../../lang/python25/PLIST.common
.if exists(${.CURDIR}/../../lang/python25/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python25/PLIST.${OPSYS}
.endif

.if ${OPSYS} == "NetBSD"
PRIVILEGED_STAGES+=	clean
# XXX work around a botched autoconf check which ignores libintl
CONFIGURE_ENV+=		ac_cv_func_bind_textdomain_codeset=yes
.endif

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
PY_PLATNAME=	${LOWER_OPSYS}
USE_TOOLS+=	gmake
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
CONFIGURE_ENV+=	ac_cv_header_netpacket_packet_h=no
.elif ${OPSYS} == "HPUX"
PY_PLATNAME=	hp-ux11
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

PLIST_VARS+=	linux2
.if ${PY_PLATNAME} == "linux2"
PLIST.linux2=	yes
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
    ${PY_PLATNAME} == "linux2"
PLIST.oss=	yes
.endif

# Make sure python modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes

.  if empty(OS_VERSION:M[1-9].*)
CFLAGS+=		-D_DARWIN_C_SOURCE
.  endif
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

.if ${OPSYS} == "OSF1"
# configure complains about buggy getaddrinfo()
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(BUILDLINK_TRANSFORM)
MAKE_ENV+=	PY_BDB_TRANSFORM=${BUILDLINK_TRANSFORM:Q}
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

TEST_TARGET=	test
INSTALL_TARGET=	altinstall

REPLACE_INTERPRETER+=	py25
REPLACE.py25.old=	.*python[^ ]*
REPLACE.py25.new=	${PREFIX}/bin/python${PY_VER_SUFFIX}
REPLACE_FILES.py25=	Lib/*.py Lib/*/*.py Lib/*/*/*.py

post-extract:
	${MV} ${WRKSRC}/Lib/smtpd.py ${WRKSRC}/Lib/smtpd${PY_VER_SUFFIX}.py
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}

.if ${OPSYS} == "HPUX"
post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython2.5.sl \
		${DESTDIR}${PREFIX}/lib/libpython2.5.sl.1.0
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
