# $NetBSD: Makefile,v 1.9 2003/09/18 16:25:29 jmmv Exp $

DISTNAME=		fileutils-4.1-154.i386
PKGNAME=		suse_vmware-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE_UPD:=a1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package to support running VMware

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base
DEPENDS+= 		suse_x11>=${SUSE_VERSION}:../../emulators/suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST=		EMULSUBDIR=${EMULSUBDIR}

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}
RPMIGNOREPATH=		usr

post-install:
	${LN} -fs /etc/fstab ${EMULDIR}/etc/mtab
	@${GREP} -v '^#' ${FILESDIR}/device-links | \
	${AWK} '{print("${LN} -fs "$$1" ${EMULDIR}/dev/"$$2)}' | \
	${SH} -
	@${GREP} -v '^#' ${FILESDIR}/device-links | \
	${AWK} '{print("@exec ln -fs "$$1" %D/${EMULSUBDIR}/dev/"$$2)}' \
	  >>${PLIST_SRC}
	@${GREP} -v '^#' ${FILESDIR}/device-links | \
	${AWK} '{print("@unexec rm -f %D/${EMULSUBDIR}/dev/"$$2)}' \
	  >>${PLIST_SRC}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
