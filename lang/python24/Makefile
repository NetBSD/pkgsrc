# $NetBSD: Makefile,v 1.19 2006/01/23 08:00:02 recht Exp $
#

DISTNAME=	Python-2.4.2
PKGNAME=	python24-2.4.2
PKGREVISION=	3
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.4.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

# Remember to update pkgsrc/lang/python/srcdist.mk when version changes

CONFLICTS+=	python-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-threads
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	OPT=${CFLAGS:M*:Q}

PTHREAD_OPTS+=	require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

.include "../../mk/bsd.prefs.mk"

# fdatasync()
LIBS.SunOS+=		-lrt

PY_VER_SUFFIX=		2.4

PLIST_SRC=	${.CURDIR}/../../lang/python24/PLIST.common
.if exists(${.CURDIR}/../../lang/python24/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python24/PLIST.${OPSYS}
.endif
PLIST_SRC+=	${.CURDIR}/../../lang/python24/PLIST.common_end

.if ${OPSYS} == "Darwin" || ${OPSYS} == "Interix"
PY_PLATNAME=	${LOWER_OPSYS}
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME:Q}

# the dl module isn't built for 64 bit archs and Darwin
.if ${MACHINE_ARCH} == "alpha" || ${MACHINE_ARCH} == "amd64" \
	|| ${MACHINE_ARCH} == "sparc64" || ${MACHINE_ARCH} == "x86_64" \
	|| ${OPSYS} == "Darwin" || ( ${OPSYS} == "IRIX" && ${ABI} == "64" )
PLIST_SUBST+=  DLMODULE="@comment "
.else
PLIST_SUBST+=  DLMODULE=
.endif

EXTRA_SO_SUBST=		"@comment "
OSSAUDIODEV_SUBST=	"@comment "

# activate extra modules
.if ${MACHINE_ARCH} == "i386"
EXTRA_SO_SUBST=
# ossaudiodev is only available on x86 for the following platforms
.  if ${PY_PLATNAME} == "linux2" || ${PY_PLATNAME} == "freebsd4" \
	|| ${PY_PLATNAME} == "freebsd5"
OSSAUDIODEV_SUBST=
.   endif
.elif ${OPSYS} == "SunOS" || ( ${OPSYS} == "IRIX" && ${ABI} != "64" ) \
	|| ${OPSYS} == "Darwin"
EXTRA_SO_SUBST=
.endif

PLIST_SUBST+=	EXTRA_SO=${EXTRA_SO_SUBST}
PLIST_SUBST+=	OSSAUDIODEV=${OSSAUDIODEV_SUBST}

# Make sure python modules can link correctly
.if ${OPSYS} == "Darwin"
INSTALL_UNSTRIPPED=	yes
.endif

.if ${OPSYS} == "IRIX"
.  if ${ABI} == "64"
PLIST_SUBST+=	NISMODULE="@comment "
.  else
PLIST_SUBST+=	NISMODULE=
.  endif
PLIST_SUBST+=	BSDDBMODULE="@comment "
PLIST_SUBST+=	NOSHLIB="@comment "
.else
.  include "../../mk/bdb.buildlink3.mk"
MAKE_ENV+=	PY_BDB_TYPE=${BDB_TYPE:Q}
MAKE_ENV+=	PY_BDB_INCDIRS=${BDBBASE}/${BUILDLINK_INCDIRS.${BDB_TYPE}}
MAKE_ENV+=	PY_BDB_LIBDIRS=${BDBBASE}/lib
PLIST_SUBST+=	BSDDBMODULE=
PLIST_SUBST+=	NOSHLIB=
PLIST_SUBST+=	NISMODULE=
.endif

.if defined(BUILDLINK_TRANSFORM)
MAKE_ENV+=	PY_BDB_TRANSFORM=${BUILDLINK_TRANSFORM:Q}
.endif

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX:Q}

TEST_TARGET=	test
INSTALL_TARGET=	altinstall

post-extract:
	${MV} ${WRKSRC}/Lib/smtpd.py ${WRKSRC}/Lib/smtpd${PY_VER_SUFFIX}.py
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}

.if ${OPSYS} == "Darwin"
post-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} libpython2.4.2.dylib)

post-install:
	${LN} -fs ${PREFIX}/lib/libpython2.4.2.dylib	\
		${PREFIX}/lib/libpython2.4.dylib
.endif

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
