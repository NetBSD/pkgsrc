# $NetBSD: Makefile,v 1.12 2001/02/16 15:25:20 wiz Exp $
#

DISTNAME=	king-1.00-tb40-1
PKGNAME=	king-1.00
CATEGORIES=	japanese
EXTRACT_SUFX=	.i386.rpm
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ibm.co.jp/software/internet/king/
COMMENT=	The king of translator POWER+ (Linux version)

IS_INTERACTIVE=	yes
RESTRICTED=	"A commercial licence needs to be purchased from IBM Corp"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

DEPENDS=	suse_base>=6.1:../../emulators/suse_base

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
SBINDIR=	${PREFIX}/sbin
CHECK_SHLIBS=	no

RPM2PKG=	${PREFIX}/sbin/rpm2pkg
RPM2PKGARGS=	-d ${PREFIX} -f ${PLIST_SRC} -p ${EMULSUBDIR}

pre-fetch:
	@(file=""; for d in "" ${DIST_PATH:S/:/ /g}; do	\
	    if [ "X$$d" = "X" -o "X$$d" = "X${DISTDIR}" ]; then continue; fi; \
	    if [ -f $$d/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		file=${DISTNAME}${EXTRACT_SUFX}; \
	    fi; \
	  done; \
	  if [ \! $$file ]; then \
		${ECHO} "If CDROM not mounted, mount_cd9660 /dev/cd0a /cdrom; ${MAKE} DIST_PATH=/cdrom/linux"; \
		${ECHO} "If CDROM mounted to /mnt, ${MAKE} DIST_PATH=/mnt/linux"; \
		${FALSE}; \
	  fi)

do-install:
	${RM} -f ${PLIST_SRC}
	${RPM2PKG} ${RPM2PKGARGS} ${_DISTDIR}/${DIST_SUBDIR}/${DISTFILES}
	@${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" \
		>> ${PLIST_SRC}
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
