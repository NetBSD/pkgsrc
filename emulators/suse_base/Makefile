# $NetBSD: Makefile,v 1.10 1999/10/07 17:41:49 tron Exp $

DISTNAME=		suse_base-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

BUILD_DEPENDS+=		${RPMLIB}:../../misc/rpm

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4
ONLY_FOR_PLATFORM=	NetBSD-*-i386

EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		aaa_dir.rpm shlibs.rpm ldso.rpm \
			bash.rpm gppshare.rpm ncurses.rpm
RPMIGNOREPATH=		tmp usr/tmp var

LDD=			${PREFIX}/${EMULSUBDIR}/usr/bin/ldd
RPMLIB=			${LOCALBASE}/lib/librpm.a

do-build:
	${CC} ${FILESDIR}/rpm2pkg.c ${CFLAGS} -I${PREFIX}/include/rpm \
	  ${RPMLIB} -lz -o ${WRKSRC}/rpm2pkg
	@for FILE in ${PKGDIR}/PLIST ${SCRIPTDIR}/*.sh; do \
	  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
	         -e 's#@@EMULSUBDIR@@#${EMULSUBDIR}#g' \
	    <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done

do-install:
	for FILE in ${WRKDIR}/*.sh; do \
	  ${INSTALL_SCRIPT} $$FILE ${PREFIX}/sbin/`basename $$FILE .sh`; \
	done
	${INSTALL_PROGRAM} ${WRKSRC}/rpm2pkg ${PREFIX}/sbin
	${MKDIR} ${EMULDIR}/dev
	${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
	${LN} -fs /dev/null ${EMULDIR}/dev/null
	@${CP} ${WRKDIR}/PLIST ${PLIST_SRC}
	${RPM2PKG} ${RPM2PKGARGS}
	${ECHO} "@dirrm ${EMULSUBDIR}" >>${PLIST_SRC}
	${INSTALL_DATA} ${FILESDIR}/ld.so.conf ${EMULDIR}/etc
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR}
	${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" \
	  >>${PLIST_SRC}
	${SED} -e 's:#! :#! /${EMULSUBDIR}:' \
	       -e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' <${LDD} >${LDD}.new
	${MV} ${LDD}.new ${LDD}
	${CHMOD} +x ${LDD}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../suse_linux/suse.mk"
