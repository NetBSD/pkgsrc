# $NetBSD: Makefile,v 1.1.1.1 2001/02/04 07:16:30 mrg Exp $
#

.if ${MACHINE_ARCH} == "sparc64"
MACHINE32_ARCH=	sparc
.else
MACHINE32_ARCH=	${MACHINE_ARCH}
.endif

DISTNAME=		compat14-${MACHINE32_ARCH}
PKGNAME=		netbsd32_compat14-1.0
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

DEPENDS+=		netbsd32_compat15-1.0:../netbsd32_compat15

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.4/index.html

ONLY_FOR_PLATFORM=	NetBSD-*-sparc64

NO_MTREE=		# defined
SHLIB_HANDLING=		NO

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

EMULSUBDIR=		emul/aout
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
COMPAT_XLIBDIR=		${EMULSUBDIR}/usr/X11R6/lib

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR} COMPAT_XLIBDIR=${COMPAT_XLIBDIR}

do-build:
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@COMPAT_LIBDIR@,${COMPAT_LIBDIR},g" \
		-e "s,@COMPAT_XLIBDIR@,${COMPAT_XLIBDIR},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@OBJECT_FMT@,${OBJECT_FMT},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}
	if [ -d ${WRKDIR}/X11R6/lib ]; then \
		${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_XLIBDIR}; \
		${INSTALL_DATA} ${WRKDIR}/X11R6/lib/lib*.so* ${PREFIX}/${COMPAT_XLIBDIR}; \
	fi

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
