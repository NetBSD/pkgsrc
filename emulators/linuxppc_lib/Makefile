# $NetBSD: Makefile,v 1.5 2001/02/25 04:17:45 hubertf Exp $

DISTNAME=		linuxppc_lib-2000.q4.2
CATEGORIES=		emulators
MASTER_SITES=	ftp://ftp.linuxppc.org/linuxppc-halloween/software/
DISTFILES=		glibc-2.1.3-15f.ppc.rpm glib-1.2.8-3.ppc.rpm \
					libjpeg-6b-13.ppc.rpm libpng-1.0.5-3.ppc.rpm \
					libstdc++-2.10.0-2n.ppc.rpm libtermcap-2.0.8-20.ppc.rpm \
					libtiff-3.5.5-2.ppc.rpm XFree86-libs-3.3.6-20b.ppc.rpm \
					zlib-1.1.3-6.ppc.rpm ldconfig-1.9.5-16.ppc.rpm \
					libjpeg6a-6a-5.ppc.rpm xpm-3.4k-1.ppc.rpm \
					ncurses-5.0-12.ppc.rpm readline-2.2.1-7a.ppc.rpm

MAINTAINER=		p99dreyf@criens.u-psud.fr
HOMEPAGE=		http://www.linuxppc.org/

BUILD_DEPENDS+=rpm2pkg:../../pkgtools/rpm2pkg

COMMENT=			libraries to run Linux binaries on NetBSD/powerpc (includes X11)

ONLY_FOR_PLATFORM=	NetBSD-*-macppc NetBSD-*-powerpc NetBSD-*-prep \
							NetBSD-*-bebox NetBSD-*-ofppc NetBSD-*-amigappc

SHLIB_HANDLING=NO
CHECK_SHLIBS=	NO
WRKSRC=			${WRKDIR}/${DISTNAME}
DIST_SUBDIR=	linuxppc_lib
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTFILES}
EMUL_LINUX=		emul/linux
LINUX_LDCONFIG=${PREFIX}/${EMUL_LINUX}/sbin/ldconfig
RPM2PKG=			rpm2pkg
SORT=				sort
RPMARGS+=		-i usr/man -i usr/doc -i usr/info
.for TEMP in ${RPMFILES}
RPMARGS+=     ${DISTDIR}/${DIST_SUBDIR}/${TEMP}
.endfor

do-extract:
	${MKDIR} ${WRKSRC}

do-build:	#do nothing

do-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	${INSTALL_DATA_DIR} ${PREFIX}/${EMUL_LINUX}
	${RPM2PKG} -d ${PREFIX} -f ${WRKDIR}/PLIST_DYNAMIC -p emul/linux ${RPMARGS}
	${TOUCH} ${PREFIX}/${EMUL_LINUX}/etc/ld.so.cache~
	${CP} ${FILESDIR}/ld.so.conf ${PREFIX}/${EMUL_LINUX}/etc/ld.so.conf
	${LINUX_LDCONFIG} -r ${PREFIX}/${EMUL_LINUX} -v | \
		${SED} -n '/^\/.*:$$/h; /(changed)$$/{G; \
		s|[[:blank:]]\([^ ]\{1,\}\) =>.*\n/\(.*\):$$|${EMUL_LINUX}/\2/\1|p;}' \
		>> ${WRKDIR}/PLIST_DYNAMIC
	${ECHO} "${EMUL_LINUX}/etc/ld.so.cache" >> ${WRKDIR}/PLIST_DYNAMIC
	${ECHO} "${EMUL_LINUX}/etc/ld.so.conf" >> ${WRKDIR}/PLIST_DYNAMIC
	${SORT} -r ${WRKDIR}/PLIST_DYNAMIC > ${WRKDIR}/PLIST_DYNAMIC.sorted
	${MV} ${WRKDIR}/PLIST_DYNAMIC.sorted ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
