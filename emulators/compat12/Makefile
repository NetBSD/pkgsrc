# $NetBSD: Makefile,v 1.18 2000/10/14 00:17:18 jlam Exp $
#

DISTNAME=		compat12-${MACHINE_ARCH}
PKGNAME=		compat12-1.2.1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.2/index.html

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-m68k NetBSD-*-ns32k \
			NetBSD-*-sparc

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
.else
LOCALBASE=		/usr
COMPAT_LIBDIR=		lib
.endif

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR}

do-build:
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@COMPAT_LIBDIR@,${COMPAT_LIBDIR},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}  -e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@OBJECT_FMT@,${OBJECT_FMT},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
