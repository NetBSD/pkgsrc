# $NetBSD: Makefile,v 1.1.1.1 2001/01/23 22:28:44 manu Exp $

DISTNAME=		linuxppc_lib-2000.q4.1
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.linuxppc.org/linuxppc-halloween/software/
DISTFILES=		glibc-2.1.3-15f.ppc.rpm glib-1.2.8-3.ppc.rpm \
					libjpeg-6b-13.ppc.rpm libpng-1.0.5-3.ppc.rpm \
					libstdc++-2.10.0-2n.ppc.rpm libtermcap-2.0.8-20.ppc.rpm \
					libtiff-3.5.5-2.ppc.rpm XFree86-libs-3.3.6-20b.ppc.rpm \
					zlib-1.1.3-6.ppc.rpm aalib-1.2-1.ppc.rpm \
					gnome-libs-1.2.8-0_helix_1.ppc.rpm imlib-1.9.8-4.ppc.rpm \
					krb5-libs-1.1.1-25.ppc.rpm ldconfig-1.9.5-16.ppc.rpm \
					libelf-0.6.4-4.ppc.rpm libghttp-1.0.7-0_helix_1.ppc.rpm \
					libglade-0.11-1.ppc.rpm libgtop-1.0.6-1.ppc.rpm \
					libjpeg6a-6a-5.ppc.rpm libpcap-0.4-19.ppc.rpm \
					librep-0.13.2-0_helix_1.ppc.rpm xpm-3.4k-1.ppc.rpm \
					libsigc++-1.0.1-0_helix_1.ppc.rpm

MAINTAINER=		p99dreyf@criens.u-psud.fr
HOMEPAGE=		http://www.linuxppc.org/

BUILD_DEPENDS+=		rpm2cpio:../../misc/rpm

ONLY_FOR_PLATFORM=	NetBSD-*-macppc NetBSD-*-powerpc NetBSD-*-prep \
							NetBSD-*-bebox NetBSD-*-ofppc NetBSD-*-amigappc

SHLIB_HANDLING=NO
CHECK_SHLIBS=	NO
WRKSRC=			${WRKDIR}/linuxppc_lib-2000.q4.1
DIST_SUBDIR=	linuxppc_lib
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTFILES}
RPM2CPIO=	${PREFIX}/bin/rpm2cpio
CPIO=			cpio
SORT=			sort
EMUL_LINUX=	emul/linux

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC}; for i in ${RPMFILES}; do \
		${ECHO} -n "Extracting $$i... " ; \
		${RPM2CPIO} ${DISTDIR}/${DIST_SUBDIR}/$$i | ${CPIO} -u -d -i ;\
	done ; \

do-build:
	${RM}	-f ${WRKSRC}/etc/*.orig

do-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	${MKDIR} ${PREFIX}/${EMUL_LINUX}
	for d in `${FIND} ${WRKSRC}/etc -type d | ${SORT} -r`; do \
		target=`${ECHO} $$d | ${SED} 's|${WRKSRC}|${PREFIX}/${EMUL_LINUX}|'`; \
		files=`${LS} -l $$d | \
				${AWK} -v d=$$d '{if ($$0~/^-/) {print d "/" $$9}}'` ; \
		links=`${LS} -l $$d | \
				${AWK} -v d=$$d '{if ($$0~/^l/) {print d "/" $$9}}'` ; \
		${MKDIR} $$target ; \
		if [ "x$$links" != "x" ] ; then \
			${ECHO} "$$links" ; \
			for l in $$links ; do \
				name=`${ECHO} $$l | ${SED} 's|^.*/\([^/]*\)$$|\1|'` ; \
				${LN} -sf `${LS} -l $$l | ${AWK} '{print $$11}'` $$target/$$name ; \
			done ; \
			${ECHO} $$links | ${SED} 's|${WRKSRC}|${EMUL_LINUX}|g' | \
				${TR} ' ' '\n' >> ${WRKDIR}/PLIST_DYNAMIC ; \
		fi; \
		if [ "x$$files" != "x" ] ; then \
			${ECHO} "$$files" ; \
			${INSTALL} -c -o root -g wheel -m 644 $$files $$target/ ; \
			${ECHO} $$files | ${SED} 's|${WRKSRC}|${EMUL_LINUX}|g' | \
				${TR} ' ' '\n' >> ${WRKDIR}/PLIST_DYNAMIC ; \
		fi; \
		${ECHO} $$target | ${SED} 's|${PREFIX}/|@dirrm |' >> \
			${WRKDIR}/PLIST_DYNAMIC ; \
	done;
	for d in `${FIND} ${WRKSRC}/lib ${WRKSRC}/usr/lib \
				${WRKSRC}/usr/X11R6/lib ${WRKSRC}/usr/kerberos/lib \
				${WRKSRC}/usr/share -type d | ${SORT} -r`; do \
		target=`${ECHO} $$d | ${SED} 's|${WRKSRC}|${PREFIX}/${EMUL_LINUX}|'`; \
		files=`${LS} -l $$d | \
				${AWK} -v d=$$d '{if ($$0~/^-/) {print d "/" $$9}}'` ; \
		links=`${LS} -l $$d | \
				${AWK} -v d=$$d '{if ($$0~/^l/) {print d "/" $$9}}'` ; \
		${MKDIR} $$target ; \
		if [ "x$$links" != "x" ] ; then \
			${ECHO} "$$links" ; \
			for l in $$links ; do \
				name=`${ECHO} $$l | ${SED} 's|^.*/\([^/]*\)$$|\1|'` ; \
				${LN} -sf `${LS} -l $$l | ${AWK} '{print $$11}'` $$target/$$name ; \
			done ; \
			${ECHO} $$links | ${SED} 's|${WRKSRC}|${EMUL_LINUX}|g' | \
				${TR} ' ' '\n' >> ${WRKDIR}/PLIST_DYNAMIC ; \
		fi; \
		if [ "x$$files" != "x" ] ; then \
			${ECHO} "$$files" ; \
			${INSTALL} -c -o root -g wheel -m 755 $$files $$target/ ; \
			${ECHO} $$files | ${SED} 's|${WRKSRC}|${EMUL_LINUX}|g' | \
				${TR} ' ' '\n' >> ${WRKDIR}/PLIST_DYNAMIC ; \
		fi ; \
		${ECHO} $$target | ${SED} 's|${PREFIX}/|@dirrm |' >> \
			${WRKDIR}/PLIST_DYNAMIC ; \
	done;
	${INSTALL} -c -o root -g wheel -m 755 ${WRKSRC}/sbin/ldconfig \
		${PREFIX}/sbin/ldconfig-linux
	${ECHO} "sbin/ldconfig-linux" >> ${WRKDIR}/PLIST_DYNAMIC
	${TOUCH} ${PREFIX}/${EMUL_LINUX}/etc/ld.so.cache~
	${PREFIX}/sbin/ldconfig-linux -v | \
		${SED} -n '/^\/.*:$$/h; /(changed)$$/{G; \
		s|[[:blank:]]\([^ ]\{1,\}\) =>.*\n/\(.*\):$$|${EMUL_LINUX}/\2/\1|p;}' \
		>> ${WRKDIR}/PLIST_DYNAMIC
	${ECHO} "${EMUL_LINUX}/etc/ld.so.cache" >> ${WRKDIR}/PLIST_DYNAMIC
	${SORT} -r ${WRKDIR}/PLIST_DYNAMIC > ${WRKDIR}/PLIST_DYNAMIC.sorted
	${MV} ${WRKDIR}/PLIST_DYNAMIC.sorted ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
