# $NetBSD: Makefile,v 1.8 1999/06/29 22:48:19 tron Exp $

DISTNAME=		suse_base-6.1
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/i386/6.1/suse/a1/ \
			ftp://ftp.cs.unm.edu/mirrors/SuSE61/suse/a1/
DISTFILES=		aaa_dir.rpm shlibs.rpm ldso.rpm \
			bash.rpm gppshare.rpm ncurses.rpm
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS=		rpm-2.5.4:../../misc/rpm

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4

DIST_SUBDIR=		suse
MIRROR_DISTFILE= 	no

EXTRACT_ONLY=		# empty
NO_WRKSUBDIR=		yes
MANCOMPRESSED=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=		emul/linux
EMULDIR=		${PREFIX}/${EMULSUBDIR}
LDD=			${PREFIX}/${EMULSUBDIR}/usr/bin/ldd
SBINDIR=		${PREFIX}/sbin

do-build:
	@for FILE in ${PKGDIR}/PLIST ${SCRIPTDIR}/*.sh; do \
	  ${SED} -e 's#@@EMULDIR@@#${EMULDIR}#g' \
	         -e 's#@@EMULSUBDIR@@#${EMULSUBDIR}#g' \
	         -e 's#@@AWK@@#${AWK}#g' \
	         -e 's#@@PAX@@#${PAX}#g' \
	         -e 's#@@PREFIX@@#${PREFIX}#g' \
	    <$$FILE >${WRKDIR}/`basename $$FILE`; \
	done

do-install:
	cd ${WRKDIR}; \
	for FILE in *.sh; do \
	  ${INSTALL_SCRIPT} $$FILE ${SBINDIR}/`basename $$FILE .sh`; \
	done
	${MKDIR} ${EMULDIR}/dev
	${LN} -fs /dev/sound ${EMULDIR}/dev/dsp
	${LN} -fs /dev/null ${EMULDIR}/dev/null
	@${CP} ${WRKDIR}/PLIST ${PLIST_SRC}
	cd ${_DISTDIR} && \
	${SBINDIR}/rpm2pkg ${DISTFILES} | \
	${EGREP} -v '${EMULSUBDIR}/(tmp|usr/tmp|var)' >>${PLIST_SRC}
	@cd ${EMULDIR} && ${RM} -rf tmp usr/tmp var
	${INSTALL_DATA} ${FILESDIR}/ld.so.conf ${EMULDIR}/etc
	${SED} -e 's:#! :#! /${EMULSUBDIR}:' \
	       -e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' <${LDD} >${LDD}.new
	${MV} ${LDD}.new ${LDD}
	${CHMOD} +x ${LDD}
	@${ECHO} "@unexec rm -rf %D/${EMULSUBDIR}" >>${PLIST_SRC}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
