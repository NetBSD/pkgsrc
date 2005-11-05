# $NetBSD: Makefile,v 1.23.4.1 2005/11/05 15:47:36 salo Exp $
#

DISTNAME=	Python-2.1.3
PKGNAME=	python21-2.1.3
PKGREVISION=	8
CATEGORIES=	lang python
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.1.3/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.python.org/
COMMENT=	Interpreted, interactive, object-oriented programming language

CONFLICTS+=	python-[0-9]*

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

PTHREAD_OPTS=   require
.include "../../mk/pthread.buildlink3.mk"
.if ${PTHREAD_TYPE} == "pth"
CONFIGURE_ARGS+=	--with-pth
.endif

PY_VER_SUFFIX=	2.1

BUILD_TARGET=		all ./Lib/plat-${PY_PLATNAME}
INSTALL_TARGET=		altinstall

.include "../../mk/bsd.prefs.mk"

PLIST_SRC=	${.CURDIR}/../../lang/python21/PLIST.common
.if exists(${.CURDIR}/../../lang/python21/PLIST.${OPSYS})
PLIST_SRC+=	${.CURDIR}/../../lang/python21/PLIST.${OPSYS}
.endif
PLIST_SRC+=	${.CURDIR}/../../lang/python21/PLIST.common_end

.if ${OPSYS} == "Darwin"
PY_PLATNAME=	${LOWER_OPSYS}
.elif ${OPSYS} == "IRIX"
PY_PLATNAME=	${LOWER_OPSYS:C/\..*//}
.elif ${OPSYS} == "SunOS"
PY_PLATNAME=	sunos${OS_VERSION:C/\..*//}
.else
PY_PLATNAME=	${LOWER_OPSYS}${OS_VERSION:C/\..*//}
.endif
PLIST_SUBST+=	PY_PLATNAME=${PY_PLATNAME}

PLAT_SOCKET=	"@comment "
PLAT_TERMIOS=	"@comment "
.if !empty(MACHINE_PLATFORM:MNetBSD-[2-9].*)
.  if exists(/usr/include/sys/socket.h)
PLAT_SOCKET=	""
.  endif
.  if exists(/usr/include/termios.h)
PLAT_TERMIOS=	""
.  endif
.endif
PLIST_SUBST+=	PLAT_SOCKET=${PLAT_SOCKET} PLAT_TERMIOS=${PLAT_TERMIOS}

# bsddb.so is not built on Solaris (or IRIX?)
BSDDB=
.if ${OPSYS} == "SunOS" || ${OPSYS} == "IRIX"
BSDDB=		"@comment "
.else
.include "../../mk/bdb.buildlink3.mk"
MAKE_ENV+=	PY_BDB_TYPE=${BDB_TYPE}
MAKE_ENV+=	PY_BDB_INCDIRS=${BDBBASE}/${BUILDLINK_INCDIRS.${BDB_TYPE}}
MAKE_ENV+=	PY_BDB_LIBDIRS=${BDBBASE}/lib
.endif
PLIST_SUBST+=	BSDDB=${BSDDB}

PLIST_SUBST+=	PY_VER_SUFFIX=${PY_VER_SUFFIX}

post-extract:
	${MV} ${WRKSRC}/Tools/scripts/pydoc ${WRKSRC}/Tools/scripts/pydoc${PY_VER_SUFFIX}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# This comes after bsd.pkg.mk so that the LDFLAGS here overrides the one
# set earlier in the environment (last definition wins).
#
.if ${OBJECT_FMT} == "a.out"
MAKE_ENV+=	LDFLAGS="${LDFLAGS:S/-Wl,//}"
.endif
