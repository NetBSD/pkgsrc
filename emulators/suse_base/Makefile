# $NetBSD: Makefile,v 1.27 2002/02/22 12:39:23 tron Exp $

DISTNAME=		suse_base-${SUSE_VERSION}
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/} \
			ftp://ftp.suse.com/pub/suse/i386/update/${SUSE_VERSION}/a1/
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4
ONLY_FOR_PLATFORM=	NetBSD-*-i386

EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		aaa_dir.rpm shlibs-2.1.3-204.i386.rpm libz.rpm \
			bash.rpm gppshare.rpm ncurses.rpm sh_utils.rpm
RPMIGNOREPATH=		tmp usr/tmp var

LINUX_LDD=		${PREFIX}/${EMULSUBDIR}/usr/bin/ldd

do-build:
	@for FILE in ${PKGDIR}/PLIST ${FILESDIR}/*.sh; do \
	  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
	         -e 's#@@EMULSUBDIR@@#${EMULSUBDIR}#g' \
	    <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done

do-install:
	for FILE in ${WRKDIR}/*.sh; do \
	  ${INSTALL_SCRIPT} $$FILE ${PREFIX}/sbin/`basename $$FILE .sh`; \
	done
	${INSTALL_DATA_DIR} ${EMULDIR}/dev
	${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
	${LN} -fs /dev/null ${EMULDIR}/dev/null
	@${CP} ${WRKDIR}/PLIST ${PLIST_SRC}
	${RPM2PKG} ${RPM2PKGARGS}
	${ECHO} "@dirrm ${EMULSUBDIR}" >>${PLIST_SRC}
	${INSTALL_DATA} ${FILESDIR}/ld.so.conf ${EMULDIR}/etc
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
	${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" \
	  >>${PLIST_SRC}
	${SED}	-e 's:#! :#! /${EMULSUBDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		< ${LINUX_LDD} > ${LINUX_LDD}.new
	${MV} ${LINUX_LDD}.new ${LINUX_LDD}
	${CHMOD} +x ${LINUX_LDD}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../suse_linux/Makefile.common"
