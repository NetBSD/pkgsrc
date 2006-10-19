# $NetBSD: Makefile,v 1.17 2006/10/19 19:39:04 wiz Exp $
#

.if ${MACHINE_ARCH} == "sparc64"
MACHINE32_ARCH=	sparc
.else
MACHINE32_ARCH=	${MACHINE_ARCH}
.endif

DISTNAME=		compat15-${MACHINE32_ARCH}
PKGNAME=		netbsd32_compat15-1.0
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.NetBSD.org/Releases/formal-1.5/index.html
COMMENT=		32-bit shared libraries for NetBSD 1.5 (and earlier) compatibility

CONFLICTS=              netbsd32_compat16-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-*-sparc64
NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

NO_MTREE=		yes
NO_BUILD=		yes
CHECK_SHLIBS_SUPPORTED=	no

FILES_SUBST+=		COMPAT_LIBEXECDIR=${COMPAT_LIBEXECDIR:Q}
FILES_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR:Q}
FILES_SUBST+=		COMPAT_XLIBDIR=${COMPAT_XLIBDIR:Q}
FILES_SUBST+=		MACHINE_ARCH=${MACHINE_ARCH:Q}
FILES_SUBST+=		OBJECT_FMT=${OBJECT_FMT:Q}
FILES_SUBST+=		LDCONFIG=${LDCONFIG:Q}

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/netbsd32
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
COMPAT_LIBEXECDIR=	${EMULSUBDIR}/usr/libexec
COMPAT_XLIBDIR=		${EMULSUBDIR}/usr/X11R6/lib

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR:Q} COMPAT_LIBEXECDIR=${COMPAT_LIBEXECDIR:Q} COMPAT_XLIBDIR=${COMPAT_XLIBDIR:Q}

# XXX using pax to copy symlinks properly.
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	(cd ${WRKDIR}/lib; ${PAX} -rwv lib*.so* ${PREFIX}/${COMPAT_LIBDIR}; \
	 ${CHOWN} ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/${COMPAT_LIBDIR}/lib*.so*; \
	 ${CHMOD} 555 ${PREFIX}/${COMPAT_LIBDIR}/lib*.so* )
	if [ -d ${WRKDIR}/X11R6/lib ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_XLIBDIR}; \
		(cd ${WRKDIR}/X11R6/lib; ${PAX} -rwv lib*.so* ${PREFIX}/${COMPAT_XLIBDIR}; \
		 ${CHOWN} ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/${COMPAT_XLIBDIR}/lib*.so*; \
		 ${CHMOD} 555 ${PREFIX}/${COMPAT_XLIBDIR}/lib*.so* ) \
	fi
	if [ -d ${WRKDIR}/libexec ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBEXECDIR}; \
		(cd ${WRKDIR}/libexec; ${PAX} -rwv ld.*so ${PREFIX}/${COMPAT_LIBEXECDIR}; \
		 ${CHOWN} ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/${COMPAT_LIBEXECDIR}/ld.*so; \
		 ${CHMOD} 555 ${PREFIX}/${COMPAT_LIBEXECDIR}/ld.*so ) \
	fi

.include "../../mk/bsd.pkg.mk"
