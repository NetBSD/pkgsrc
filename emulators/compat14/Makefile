# $NetBSD: Makefile,v 1.1.1.1 2001/02/04 08:03:39 mrg Exp $
#

DISTNAME=		compat14-${MACHINE_ARCH}
PKGNAME=		compat14-1.4.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.4/index.html

ONLY_FOR_PLATFORM=	NetBSD-*-sparc NetBSD-*-i386
NOT_FOR_PLATFORM=	NetBSD-1.3*-* NetBSD-1.4*-*

NO_MTREE=		# defined
SHLIB_HANDLING=		NO

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

.include "../../mk/bsd.prefs.mk"

# This installs in /usr (or /emul/aout/usr) to avoid dynamic linker annoyances
.if ${OBJECT_FMT} == "ELF" && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "sparc")
EMULSUBDIR=		emul/aout
COMPAT_LIBDIR=		${EMULSUBDIR}/usr/lib
COMPAT_XLIBDIR=		${EMULSUBDIR}/usr/X11R6/lib
.else
LOCALBASE=		/usr
COMPAT_LIBDIR=		lib
COMPAT_XLIBDIR=		X11R6/lib
.endif

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

# note that the INSTALL_DATA for the lib*.so symlinks will copy the file, not the symlink.
# FIXME.
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
