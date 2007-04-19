# $NetBSD: Makefile,v 1.9 2007/04/19 15:30:20 xtraeme Exp $

DISTNAME=		suse_base-${SUSE_VERSION}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4 linuxppc_lib-[0-9]*

# these files are handled by manually during de-/installation/pkg_add
CHECK_FILES_SKIP+=	${PREFIX}/${EMULSUBDIR}/dev/.*
CHECK_FILES_SKIP+=	${PREFIX}/${EMULSUBDIR}/etc/ld.so.cache

EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q} LINUX_LIB=${LINUX_LIB:Q} \
			SUSE_COMPAT32_SUFFIX=${SUSE_COMPAT32_SUFFIX:Q}

.include "../../mk/bsd.prefs.mk"

RPMIGNOREPATH=		./etc/bash.bashrc ./etc/bash_completion.d \
			./etc/cron.daily ./etc/csh.cshrc ./etc/csh.login \
			./etc/inittab ./etc/hushlogins ./etc/java \
			./etc/mailcap ./etc/mime.types ./etc/nsswitch.conf \
			./etc/pam.d ./etc/profile ./etc/profile.dos \
			./etc/rc.d.README ./etc/rpc ./etc/shells ./etc/ttytype

LINUX_LDD=		${PREFIX}/${EMULSUBDIR}/usr/bin/ldd
LINUX_LIB?=		lib

INSTALLATION_DIRS=	sbin

SUSE_INCLUDE_MAKEFILE_ARCH=	yes

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
	${INSTALL_SCRIPT} ${FILESDIR}/linux-mkpwd.sh \
		${PREFIX}/sbin/linux${SUSE_COMPAT32_SUFFIX}-mkpwd
	${INSTALL_DATA_DIR} ${EMULDIR}/dev
	${INSTALL_DATA} /dev/MAKEDEV ${EMULDIR}/dev
	if [ -f /dev/MAKEDEV.subr ]; then \
	  ${INSTALL_DATA} /dev/MAKEDEV.subr ${EMULDIR}/dev; \
	fi
	cd ${EMULDIR}/dev && ${SH} ./MAKEDEV  std audio
	cd ${EMULDIR}/dev && ${LN} -fs sound dsp
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
	${SED}	-e 's:#! :#! ${EMULDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		< ${LINUX_LDD} > ${LINUX_LDD}.new
	${MV} ${LINUX_LDD}.new ${LINUX_LDD}
	${CHMOD} +x ${LINUX_LDD}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
