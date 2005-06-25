# $NetBSD: Makefile,v 1.10 2005/06/25 10:47:56 tron Exp $

DISTNAME=		suse_base-${SUSE_VERSION}
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4 linuxppc_lib-[0-9]*
ONLY_FOR_PLATFORM+=	NetBSD-[2-9]*-i386 NetBSD-[3-9]*-x86_64 \
			FreeBSD-*-i386

EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR} LINUX_LIB=${LINUX_LIB}

.include "Makefile.${MACHINE_ARCH}"

RPMIGNOREPATH=		./etc/bash.bashrc ./etc/bash_completion.d \
			./etc/cron.daily ./etc/csh.cshrc ./etc/csh.login \
			./etc/inittab ./etc/hushlogins ./etc/java \
			./etc/mailcap ./etc/mime.types ./etc/nsswitch.conf \
			./etc/pam.d ./etc/profile ./etc/profile.dos \
			./etc/rc.d.README ./etc/rpc ./etc/shells ./etc/ttytype

LINUX_LDD=		${PREFIX}/${EMULSUBDIR}/usr/bin/ldd
LINUX_LIB?=		lib

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	sbin

do-build:
	@for FILE in ${FILESDIR}/SuSE-release ${FILESDIR}/*.sh; do \
	  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
	         -e 's#@@EMULSUBDIR@@#${EMULSUBDIR}#g' \
	         -e 's#@@LINUX_LIB@@#${LINUX_LIB}#g' \
	         -e 's#@@VERSION@@#${SUSE_VERSION}#g' \
	         -e 's#@@ARCH@@#${SUSE_ARCH}#g' \
	    $$FILE >${WRKDIR}/`basename $$FILE`; \
	done

do-install:
	for FILE in ${WRKDIR}/*.sh; do \
	  ${INSTALL_SCRIPT} $$FILE ${PREFIX}/sbin/`basename $$FILE .sh`; \
	done
	${INSTALL_DATA_DIR} ${EMULDIR}/dev
	${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
	${LN} -fs /dev/null ${EMULDIR}/dev/null
	${LN} -fs /dev/tty ${EMULDIR}/dev/tty
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
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
