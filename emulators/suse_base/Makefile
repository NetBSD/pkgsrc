# $NetBSD: Makefile,v 1.51 2004/10/01 10:37:33 grant Exp $

DISTNAME=		suse_base-${SUSE_VERSION}
PKGREVISION=		6
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/} \
			${MASTER_SITE_SUSE_UPD:=a1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4 linuxppc_lib-[0-9]*
ONLY_FOR_PLATFORM=	NetBSD-1.5Z[C-Z]-i386 NetBSD-1.6*-i386
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	NetBSD-1.6[L-Z]-powerpc NetBSD-1.6Z[A-Z]-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-powerpc
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386

NO_BUILDLINK=		YES
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		aaa_dir.rpm gppshare.rpm ncurses.rpm \
			readline.rpm bash.rpm sh-utils.rpm

.include "../../emulators/suse_linux/arch.mk"

.if ${SUSE_ARCH} == "i386"
RPMFILES+=	glibc-2.2.4-78.${SUSE_ARCH}.rpm libz-1.1.3-597.${SUSE_ARCH}.rpm
.elif ${SUSE_ARCH} == "ppc"
RPMFILES+=	glibc-2.2.4-69.${SUSE_ARCH}.rpm libz-1.1.3-432.${SUSE_ARCH}.rpm

BUILD_DEPENDS+=	fixelfprot>=20040714:../../sysutils/fixelfprot
.else
RPMFILES+=	glibc.rpm libz.rpm
.endif

RPMIGNOREPATH=		tmp usr/tmp var

LINUX_LDD=		${PREFIX}/${EMULSUBDIR}/usr/bin/ldd

.include "../../mk/bsd.prefs.mk"

do-build:
	@for FILE in ${PKGDIR}/PLIST ${FILESDIR}/*.sh; do \
	  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
	         -e 's#@@EMULSUBDIR@@#${EMULSUBDIR}#g' \
	    <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done
	${SED} -e 's#@@VERSION@@#${SUSE_VERSION}#g' \
	       -e 's#@@ARCH@@#${SUSE_ARCH}#g' \
	    <${FILESDIR}/SuSE-release >${WRKDIR}/SuSE-release

do-install:
	for FILE in ${WRKDIR}/*.sh; do \
	  ${INSTALL_SCRIPT} $$FILE ${PREFIX}/sbin/`basename $$FILE .sh`; \
	done
	${INSTALL_DATA_DIR} ${EMULDIR}/dev
	${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
	${LN} -fs /dev/null ${EMULDIR}/dev/null
	${LN} -fs /dev/tty ${EMULDIR}/dev/tty
	@${CP} ${WRKDIR}/PLIST ${PLIST_SRC}
	${RPM2PKG} ${RPM2PKGARGS}
	${ECHO} "@dirrm ${EMULSUBDIR}" >>${PLIST_SRC}
	${INSTALL_DATA} ${WRKDIR}/SuSE-release ${EMULDIR}/etc
	${INSTALL_DATA} ${FILESDIR}/ld.so.conf ${EMULDIR}/etc
.if ${OPSYS} == "FreeBSD"
	${BRANDELF} -t Linux ${EMULDIR}/sbin/ldconfig
.endif
.if ${OPSYS} == "NetBSD" && ${SUSE_ARCH} == "ppc"
	${LOCALBASE}/sbin/fixelfprot ${EMULDIR}/sbin/ldconfig
.endif
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
	${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" \
	  >>${PLIST_SRC}
	${SED}	-e 's:#! :#! /${EMULSUBDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		< ${LINUX_LDD} > ${LINUX_LDD}.new
	${MV} ${LINUX_LDD}.new ${LINUX_LDD}
	${CHMOD} +x ${LINUX_LDD}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
