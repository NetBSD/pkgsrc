# $NetBSD: Makefile,v 1.1.1.1 2002/11/08 16:23:02 mrg Exp $
#

.if ${MACHINE_ARCH} == "sparc64"
MACHINE32_ARCH=	sparc
.else
MACHINE32_ARCH=	${MACHINE_ARCH}
.endif

DISTNAME=		compat16-${MACHINE32_ARCH}
PKGNAME=		netbsd32_compat16-1.0
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.6/index.html
COMMENT=		32-bit shared libraries for NetBSD 1.6 (and earlier) compatibility

CONFLICTS=		netbsd32_compat15-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-*-sparc64

NO_MTREE=		# defined
SHLIB_HANDLING=		NO

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/netbsd32
COMPAT_LIBDIR=		${PREFIX}/${EMULSUBDIR}/usr/lib
COMPAT_LIBEXECDIR=	${PREFIX}/${EMULSUBDIR}/usr/libexec
COMPAT_XLIBDIR=		${PREFIX}/${EMULSUBDIR}/usr/X11R6/lib

PLIST_SUBST+=		COMPAT_EMULSUBDIR=${EMULSUBDIR}

do-build:
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@COMPAT_EMULSUBDIR@,${COMPAT_EMULSUBDIR},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@OBJECT_FMT@,${OBJECT_FMT},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

# XXX using pax to copy symlinks properly.
do-install:
	${INSTALL_DATA_DIR} ${COMPAT_LIBDIR} ${COMPAT_XLIBDIR} \
		${COMPAT_LIBEXECDIR}
	(cd ${WRKDIR}/usr/lib; pax -rwv lib*.so* i18n/lib*.so* ${COMPAT_LIBDIR})
	(cd ${WRKDIR}/usr/X11R6/lib; pax -rwv lib*.so* ${COMPAT_XLIBDIR})
	(cd ${WRKDIR}/usr/libexec; pax -rwv ld.*so ${COMPAT_LIBEXECDIR})
	chown ${ROOT_USER}:${ROOT_GROUP} \
		${COMPAT_LIBDIR}/lib*.so* ${COMPAT_LIBDIR}/i18n/lib*.so* \
		${COMPAT_XLIBDIR}/lib*.so* ${COMPAT_LIBEXECDIR}/ld.*so
	chmod 555 ${COMPAT_LIBDIR}/lib*.so* ${COMPAT_LIBDIR}/i18n/lib*.so* \
		  ${COMPAT_XLIBDIR}/lib*.so* ${COMPAT_LIBEXECDIR}/ld.*so

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
