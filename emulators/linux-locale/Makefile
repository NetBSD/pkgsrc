# $NetBSD: Makefile,v 1.1.1.1 2000/01/07 05:23:30 sakamoto Exp $
#

DISTNAME=	libwcsmbs-0.0.4-4jrpm
PKGNAME=	linux-locale-0.4.11
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.linux.or.jp/pub/RPM/RPMS/i386-glibc/ \
		ftp://mirror.nucba.ac.jp/pub/JRPM/RPMS/i386-glibc/ \
		ftp://ftp.lab.kdd.co.jp/Linux/jrpm/RPMS/i386-glibc/ \
		ftp://ftp.cc.miyazaki-u.ac.jp/pub/OS/Linux/JRPM/RPMS/i386-glibc/
EXTRACT_SUFX=	.i386.rpm
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		wcsmbs-locale-0.4.11-1jrpm${EXTRACT_SUFX}

MAINTAINER=	sakamoto@netbsd.org

ONLY_FOR_PLATFORM=	*-*-i386

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
DEPENDS=	suse_linux-6.1p1:../../emulators/suse_linux
.endif

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC
DEINSTALL_SRC=	${PKGDIR}/DEINSTALL
DEINSTALL_FILE=	${WRKDIR}/DEINSTALL

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
EMULPRELOAD=	${EMULDIR}/etc/ld.so.preload

RPM2PKG=	${PREFIX}/sbin/rpm2pkg
RPM2PKGARGS=	-d ${PREFIX} -f ${PLIST_SRC} -p ${EMULSUBDIR}
.for TEMP in ${DISTFILES}
RPM2PKGARGS+=	${DISTDIR}/${DIST_SUBDIR}/${TEMP}
.endfor

do-install:
	@if [ -f ${PKGDIR}/PLIST ]; then \
	  ${CP} ${PKGDIR}/PLIST ${PLIST_SRC}; \
	else \
	  ${RM} -f ${PLIST_SRC}; \
	fi
	${RPM2PKG} ${RPM2PKGARGS}
	@if ${GREP} -q 'lib.*\.so' ${PLIST_SRC}; then \
	  ${ECHO_MSG} "===>   [Automatic Linux shared object handling]"; \
	  ${EMULDIR}/sbin/ldconfig -r ${EMULDIR}; \
	  ${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" >>${PLIST_SRC}; \
	  ${ECHO} "@unexec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR} 2>/dev/null" >>${PLIST_SRC}; \
	fi

post-install:
	@${ECHO_MSG} "===>   [Automatic Linux shared object preload handling]"
	@grep -v 'libwcsmbs\.so' ${EMULPRELOAD} \
		> ${WRKDIR}/preload 2> /dev/null || ${TRUE}
	@${MV} ${WRKDIR}/preload ${EMULPRELOAD}
	@${ECHO} "libwcsmbs.so.0" >> ${EMULPRELOAD}
	@${SED} -e 's|$${EMULPRELOAD}|${EMULPRELOAD}|g' \
		${DEINSTALL_SRC} > ${DEINSTALL_FILE}

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
