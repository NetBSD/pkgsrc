# $NetBSD: Makefile,v 1.5 2004/10/02 01:26:19 wiz Exp $

DISTNAME=		suse_base-${SUSE_VERSION}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4 linuxppc_lib-[0-9]*
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-i386 FreeBSD-*-i386

NO_BUILDLINK=		YES
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		aaa_base-9.1-0.${SUSE_ARCH}.rpm \
			bash-2.05b-305.${SUSE_ARCH}.rpm \
			coreutils-5.2.1-23.${SUSE_ARCH}.rpm \
			glibc-2.3.3-98.${SUSE_ARCH}.rpm \
			libgcc-3.3.3-41.${SUSE_ARCH}.rpm \
			libacl-2.2.21-54.${SUSE_ARCH}.rpm \
			libattr-2.4.12-56.${SUSE_ARCH}.rpm \
			libselinux-1.8-16.${SUSE_ARCH}.rpm \
			libstdc++-3.3.3-41.${SUSE_ARCH}.rpm \
			ncurses-5.4-59.${SUSE_ARCH}.rpm \
			readline-4.3-306.${SUSE_ARCH}.rpm \
			zlib-1.2.1-70.${SUSE_ARCH}.rpm
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
	${INSTALL_DATA_DIR} ${EMULDIR}/proc
	${LN} -fs ${EMULDIR}/proc/mounts ${EMULDIR}/etc/mtab
.if ${OPSYS} == "FreeBSD"
	${BRANDELF} -t Linux ${EMULDIR}/sbin/ldconfig
.endif
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
	${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" \
	  >>${PLIST_SRC}
	${ECHO} "@unexec ${RMDIR} %D/${EMULSUBDIR}/etc 2>/dev/null || ${TRUE}" \
	  >>${PLIST_SRC}
	${SED}	-e 's:#! :#! /${EMULSUBDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		< ${LINUX_LDD} > ${LINUX_LDD}.new
	${MV} ${LINUX_LDD}.new ${LINUX_LDD}
	${CHMOD} +x ${LINUX_LDD}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
