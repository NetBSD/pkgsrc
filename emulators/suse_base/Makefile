# $NetBSD: Makefile,v 1.13 2000/11/01 16:03:26 itojun Exp $

DISTNAME=		suse_base-6.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tls@netbsd.org
HOMEPAGE=		http://www.suse.com/

BUILD_DEPENDS+=		${RPMLIB}:../../misc/rpm

CONFLICTS=		linux_SuSE-5.3 linux_lib-2.4 suse_base-6.1
ONLY_FOR_PLATFORM=	NetBSD-*-i386

EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
USE_LIBINTL=		yes
.if exists(/usr/include/libintl.h)
LIBINTL=		-lintl
.else
LIBINTL=		-L${LOCALBASE} -lintl
.endif

# Careful!  The ncurses-p1.rpm file doesn't come from SuSE, quite.
# It's been rebuilt to use seteuid() where an ill-advised SuSE patch
# to standard ncurses uses setfsuid(), which is basically impossible
# to emulate correctly under NetBSD.  So you'll find _this_ file _only_
# on your local NetBSD mirror, not on SuSE or its mirrors.  Don't use
# SuSE's ncurses.rpm -- it'll make things like /bin/sh dump core.
#
RPMFILES=		aaa_dir.rpm shlibs.rpm ldso.rpm libz.rpm \
			bash.rpm gppshare.rpm ncurses-p1.rpm
RPMIGNOREPATH=		tmp usr/tmp var

LINUX_LDD=		${PREFIX}/${EMULSUBDIR}/usr/bin/ldd
RPMLIB=			${LOCALBASE}/lib/librpm.a

do-build:
	${CC} ${FILESDIR}/rpm2pkg.c ${CFLAGS} -I${PREFIX}/include/rpm \
	  ${RPMLIB} -lz ${LIBINTL} -o ${WRKSRC}/rpm2pkg
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
	${SED}	-e 's:#! :#! /${EMULSUBDIR}:' \
		-e 's:^RTLD=:RTLD=/${EMULSUBDIR}:' \
		< ${LINUX_LDD} > ${LINUX_LDD}.new
	${MV} ${LINUX_LDD}.new ${LINUX_LDD}
	${CHMOD} +x ${LINUX_LDD}
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../suse_linux/suse.mk"
