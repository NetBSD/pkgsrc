# $NetBSD: Makefile,v 1.3 2001/12/05 16:03:57 agc Exp $
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

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.5/index.html
COMMENT=		32-bit shared libraries for NetBSD 1.5 (and earlier) compatibility

ONLY_FOR_PLATFORM=	NetBSD-*-sparc64

NO_MTREE=		# defined
SHLIB_HANDLING=		NO

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/netbsd32
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
COMPAT_LIBEXECDIR=	${EMULSUBDIR}/usr/libexec
COMPAT_XLIBDIR=		${EMULSUBDIR}/usr/X11R6/lib

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR} COMPAT_LIBEXECDIR=${COMPAT_LIBEXECDIR} COMPAT_XLIBDIR=${COMPAT_XLIBDIR}

do-build:
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@COMPAT_LIBDIR@,${COMPAT_LIBDIR},g" \
		-e "s,@COMPAT_LIBEXECDIR@,${COMPAT_LIBEXECDIR},g" \
		-e "s,@COMPAT_XLIBDIR@,${COMPAT_XLIBDIR},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@OBJECT_FMT@,${OBJECT_FMT},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

# XXX using pax to copy symlinks properly.
do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	(cd ${WRKDIR}/lib; pax -rwv lib*.so* ${PREFIX}/${COMPAT_LIBDIR}; \
	 chown ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/${COMPAT_LIBDIR}/lib*.so*; \
	 chmod 555 ${PREFIX}/${COMPAT_LIBDIR}/lib*.so* )
	if [ -d ${WRKDIR}/X11R6/lib ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_XLIBDIR}; \
		(cd ${WRKDIR}/X11R6/lib; pax -rwv lib*.so* ${PREFIX}/${COMPAT_XLIBDIR}; \
		 chown ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/${COMPAT_XLIBDIR}/lib*.so*; \
		 chmod 555 ${PREFIX}/${COMPAT_XLIBDIR}/lib*.so* ) \
	fi
	if [ -d ${WRKDIR}/libexec ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBEXECDIR}; \
		(cd ${WRKDIR}/libexec; pax -rwv ld.*so ${PREFIX}/${COMPAT_LIBEXECDIR}; \
		 chown ${ROOT_USER}:${ROOT_GROUP} ${PREFIX}/${COMPAT_LIBEXECDIR}/ld.*so; \
		 chmod 555 ${PREFIX}/${COMPAT_LIBEXECDIR}/ld.*so ) \
	fi

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
