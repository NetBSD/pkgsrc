# $NetBSD: Makefile,v 1.3 1999/11/23 16:54:40 hubertf Exp $
#

DISTNAME=	king-1.00-tb40-1
PKGNAME=	king-1.00
CATEGORIES=	japanese
EXTRACT_SUFX=	.i386.rpm
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ibm.co.jp/software/internet/king/

RESTRICTED=	"You should buy from IBM Corp"
NO_PACKAGE=	${RESTRICTED}
NO_CDROM=	${RESTRICTED}
MIRROR_DISTFILE=no

KINGDISTDIR?=	/cdrom/linux
DISTDIR=	${KINGDISTDIR}

DEPENDS=	suse_base-6.1p1:../../emulators/suse_base

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
PLIST_SRC=	${WRKDIR}/PLIST_DYNAMIC

EMULSUBDIR=	emul/linux
EMULDIR=	${PREFIX}/${EMULSUBDIR}
SBINDIR=	${PREFIX}/sbin

RPM2PKG=	${PREFIX}/sbin/rpm2pkg
RPM2PKGARGS=	-d ${PREFIX} -f ${PLIST_SRC} -p ${EMULSUBDIR}

do-fetch:
	@(if [ ! -f ${KINGDISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO} "If CDROM not mounted, mount_cd9660 /dev/cd0a /cdrom; ${MAKE}"; \
		${ECHO} "If CDROM mounted to /mnt, ${MAKE} KINGDISTDIR=/mnt/linux"; \
		${FALSE}; \
	fi)

do-install:
	${RM} -f ${PLIST_SRC}
	${RPM2PKG} ${RPM2PKGARGS} ${KINGDISTDIR}/${DISTFILES}
	@${ECHO} "@exec %D/${EMULSUBDIR}/sbin/ldconfig -r %D/${EMULSUBDIR}" \
		>> ${PLIST_SRC}
	${EMULDIR}/sbin/ldconfig -r ${EMULDIR} || ${TRUE}

show-shlib-type:
	@${ECHO} linux-${MACHINE_ARCH}

.include "../../mk/bsd.pkg.mk"
