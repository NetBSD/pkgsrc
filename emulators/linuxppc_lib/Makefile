# $NetBSD: Makefile,v 1.23 2005/05/16 01:15:31 jlam Exp $

DISTNAME=		linuxppc_lib-2000.4.6
CATEGORIES=		emulators
MASTER_SITES+=		ftp://ftp.linuxppc.org/linuxppc-halloween/software/
MASTER_SITES+=		http://linuxppc.org/software/java/dl/motif/
RPMFILES=	glibc-2.1.3-15f.ppc.rpm glib-1.2.8-3.ppc.rpm \
		libjpeg-6b-13.ppc.rpm libpng-1.0.5-3.ppc.rpm \
		libstdc++-2.10.0-2n.ppc.rpm libtermcap-2.0.8-20.ppc.rpm \
		libtiff-3.5.5-2.ppc.rpm XFree86-libs-3.3.6-20b.ppc.rpm \
		zlib-1.1.3-6.ppc.rpm ldconfig-1.9.5-16.ppc.rpm \
		libjpeg6a-6a-5.ppc.rpm xpm-3.4k-1.ppc.rpm \
		ncurses-5.0-12.ppc.rpm readline-2.2.1-7a.ppc.rpm
DISTFILES+=	${RPMFILES}
DISTFILES+=	openmotif-2.1.30-3_MLI_jdk.tar.gz

MAINTAINER=		p99dreyf@criens.u-psud.fr
HOMEPAGE=		http://www.linuxppc.org/
COMMENT=		Libraries to run Linux binaries on NetBSD/powerpc (includes X11)

BUILD_DEPENDS+=		rpm2pkg-1.2:../../pkgtools/rpm2pkg

CONFLICTS=		suse_base-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5[U-Z]-powerpc NetBSD-1.5Z[A-Z]-powerpc \
			NetBSD-1.6*-powerpc NetBSD-[2-9]*-powerpc

WRKSRC=			${WRKDIR}/${DISTNAME}
SHLIB_HANDLING=		NO
CHECK_SHLIBS=		NO
DIST_SUBDIR=		linuxppc_lib
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

PKGSRC_USE_TOOLS+=	gtar

EMUL_LINUX=		emul/linux
LINUX_LDCONFIG=		${PREFIX}/${EMUL_LINUX}/sbin/ldconfig
RPM2PKG=		rpm2pkg
SORT=			sort
RPMARGS+=		-i usr/man -i usr/doc -i usr/info
.for TEMP in ${RPMFILES}
RPMARGS+=		${DISTDIR}/${DIST_SUBDIR}/${TEMP}
.endfor

do-extract:
	${MKDIR} ${WRKSRC}

do-build:	#do nothing

do-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	${INSTALL_DATA_DIR} ${PREFIX}/${EMUL_LINUX}
	${INSTALL_DATA_DIR} /${EMUL_LINUX}
	${RPM2PKG} -d ${PREFIX} -f ${WRKDIR}/PLIST_DYNAMIC -p emul/linux ${RPMARGS}

	# Fix Linux's ldd paths (ldd is a shell script on Linux)
	${SED} 's|^\(TEXTDOMAINDIR=\)\(/usr/share/locale\)|\1${PREFIX}/${EMUL_LINUX}\2|; \
		s|^\(RTLD=\)\(/lib/ld.so.1\)|\1${PREFIX}/${EMUL_LINUX}\2|' \
		${PREFIX}/${EMUL_LINUX}/usr/bin/ldd > \
		${PREFIX}/${EMUL_LINUX}/usr/bin/ldd.new
	${MV} ${PREFIX}/${EMUL_LINUX}/usr/bin/ldd.new \
	    ${PREFIX}/${EMUL_LINUX}/usr/bin/ldd
	${CHMOD} 755 ${PREFIX}/${EMUL_LINUX}/usr/bin/ldd

	# Unpack shared libraries for OpenMotif
	cd ${PREFIX}/${EMUL_LINUX}/usr/X11R6 ; ${GTAR} -x 'lib/*.so*' \
	    -zvf ${DISTDIR}/${DIST_SUBDIR}/openmotif-2.1.30-3_MLI_jdk.tar.gz | \
	    ${SED} -e "s|^|${EMUL_LINUX}/usr/X11R6/|" >> ${WRKDIR}/PLIST_DYNAMIC

	# Make the link /usr/pkg/emul/linux -> /emul/linux
	${TEST} -f /emul/linux/lib/ld.so.1 || ( ${RMDIR} /${EMUL_LINUX} && \
	    ${LN} -sf ${PREFIX}/${EMUL_LINUX} /${EMUL_LINUX} )

	# Create ld.so.conf and ld.so.cache. (uses Linux's ldconfig)
	${TOUCH} ${PREFIX}/${EMUL_LINUX}/etc/ld.so.cache~
	${CP} ${FILESDIR}/ld.so.conf ${PREFIX}/${EMUL_LINUX}/etc/ld.so.conf
	${LINUX_LDCONFIG} -r ${PREFIX}/${EMUL_LINUX} -v | \
		${SED} -n '/^\/.*:$$/h; /(changed)$$/{G; \
		s|[[:blank:]]\([^ ]\{1,\}\) =>.*\n/\(.*\):$$|${EMUL_LINUX}/\2/\1|p;}' \
		>> ${WRKDIR}/PLIST_DYNAMIC
	${ECHO} "${EMUL_LINUX}/etc/ld.so.conf" >> ${WRKDIR}/PLIST_DYNAMIC
	${SORT} -r ${WRKDIR}/PLIST_DYNAMIC > ${WRKDIR}/PLIST_DYNAMIC.sorted
	${MV} ${WRKDIR}/PLIST_DYNAMIC.sorted ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
