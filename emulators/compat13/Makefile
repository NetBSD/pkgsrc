# $NetBSD: Makefile,v 1.11 2001/05/07 12:51:25 dmcmahill Exp $
#

DISTNAME=		compat13-${MACHINE_ARCH}${PKGMINOR}
PKGNAME=		compat13-1.3.3${PKGMINOR}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.netbsd.org/Releases/formal-1.3/index.html
COMMENT=		Shared libraries for NetBSD 1.3 (and earlier) compatibility

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-arm32 NetBSD-*-i386 \
			NetBSD-*-m68k NetBSD-*-mipsel NetBSD-*-ns32k \
			NetBSD-*-sparc
NOT_FOR_PLATFORM=	NetBSD-1.3*-*

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

.if ${MACHINE_ARCH} == "alpha"
PLIST_SRC+=		${PKGDIR}/PLIST
PLIST_SRC+=		${PKGDIR}/PLIST.alpha
PKGMINOR=		nb1
.endif

PLIST_SUBST+=		COMPAT_LIBDIR=${COMPAT_LIBDIR}

do-build:
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@COMPAT_LIBDIR@,${COMPAT_LIBDIR},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED}	-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		-e "s,@OBJECT_FMT@,${OBJECT_FMT},g" \
		-e "s,@LDCONFIG@,${LDCONFIG},g" \
		< ${PKGDIR}/INSTALL > ${INSTALL_FILE}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${COMPAT_LIBDIR}
	${INSTALL_DATA} ${WRKDIR}/lib*.so* ${PREFIX}/${COMPAT_LIBDIR}

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
