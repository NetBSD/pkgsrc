# $NetBSD: Makefile,v 1.2 2008/04/24 04:42:00 bjs Exp $

DISTNAME=	Python-2.5.2
PKGNAME=	python25-2.5.2
PKGREVISION=	1
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.5.2/ \
		http://www.python.org/ftp/python/2.5.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

PKG_DESTDIR_SUPPORT=	user-destdir

# Remember to update pkgsrc/lang/python/srcdist.mk when version changes

CONFLICTS+=	python-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT=${CFLAGS:M*:Q}

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
PLIST_SRC+=	${.CURDIR}/../../lang/python25/PLIST.common_end

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

.if (${MACHINE_ARCH} == "alpha") || (${MACHINE_ARCH} == "amd64") || \
    (${MACHINE_ARCH} == "sparc64") || (${MACHINE_ARCH} == "x86_64") || \
    (defined(ABI) && ${ABI} == "64")
IS_64BIT_PLATFORM?=	yes
.else
IS_64BIT_PLATFORM?=	no
.endif

# the dl module isn't built for 64 bit archs and Darwin
.if !empty(IS_64BIT_PLATFORM:M[yY][eE][sS]) || (${OPSYS} == "Darwin")
PLIST_SUBST+=	DLMODULE="@comment "
.else
PLIST_SUBST+=	DLMODULE=
.endif

# setup.py causes some modules to be built if the platform is *not* 64bit.
.if !empty(IS_64BIT_PLATFORM:M[nN][oO])
PLIST_SUBST+=	EXTRA_SO=
.else
PLIST_SUBST+=	EXTRA_SO="@comment "
.endif

# ossaudiodev is only available on x86 for the following platforms
.if (${MACHINE_ARCH} == "i386") && \
    (${PY_PLATNAME} == "linux2" || ${OPSYS} == "FreeBSD")
PLIST_SUBST+=	OSSAUDIODEV=
.elif (${MACHINE_ARCH} == "x86_64") && (${PY_PLATNAME} == "linux2")
PLIST_SUBST+=	OSSAUDIODEV=
.else
PLIST_SUBST+=	OSSAUDIODEV="@comment "
.endif

# Make sure python modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

.if ${OPSYS} == "IRIX"
.  if ${ABI} == "64"
PLIST_SUBST+=	NISMODULE="@comment "
PLIST_SUBST+=	NO_NISMODULE="@comment "
.  else
PLIST_SUBST+=	NISMODULE=
PLIST_SUBST+=	NO_NISMODULE="@comment "
.  endif
PLIST_SUBST+=	BSDDBMODULE="@comment "
PLIST_SUBST+=	NOSHLIB="@comment "
.else
.  include "../../mk/bdb.buildlink3.mk"
MAKE_ENV+=	PY_BDB_TYPE=${BDB_TYPE}
MAKE_ENV+=	PY_BDB_INCDIRS=${BUILDLINK_INCDIRS.${BDB_TYPE}:S,^,${BDBBASE}/,:Q}
MAKE_ENV+=	PY_BDB_LIBDIRS=${BDBBASE}/lib
LIBS+=		${BDB_LIBS}
PLIST_SUBST+=	BSDDBMODULE=
PLIST_SUBST+=	NOSHLIB=
.  if ${OPSYS} != "NetBSD" || exists(/usr/bin/ypcat)
PLIST_SUBST+=	NISMODULE=
PLIST_SUBST+=	NO_NISMODULE="@comment "
.  else
PLIST_SUBST+=	NISMODULE="@comment "
PLIST_SUBST+=	NO_NISMODULE=
.  endif
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
REPLACE_FILES.py25=	Lib/cgi.py	# explicitly demanded to be patched
REPLACE_FILES.py25+=	Lib/bsddb/dbshelve.py Lib/test/test_bz2.py
REPLACE_FILES.py25+=	Lib/test/test_largefile.py Lib/test/test_optparse.py

post-extract:
	${MV} ${WRKSRC}/Lib/smtpd.py ${WRKSRC}/Lib/smtpd${PY_VER_SUFFIX}.py
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}

.if ${OPSYS} == "Darwin"
post-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} libpython2.5.2.dylib

post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython2.5.2.dylib	\
		${DESTDIR}${PREFIX}/lib/libpython2.5.dylib
.endif

.if ${OPSYS} == "HPUX"
post-install:
	${LN} -fs ${DESTDIR}${PREFIX}/lib/libpython2.5.sl \
		${DESTDIR}${PREFIX}/lib/libpython2.5.sl.1.0
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
