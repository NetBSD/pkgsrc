# $NetBSD: Makefile,v 1.3 2001/08/01 23:21:00 kristerw Exp $

DISTNAME=		suse_vmware-${SUSE_VERSION}
PKGNAME=		${DISTNAME}nb1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package to support running VMware

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base
DEPENDS+= 		suse_x11>=${SUSE_VERSION}:../suse_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST=		EMULSUBDIR=${EMULSUBDIR}

RPMFILES=		fileutil.rpm
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

.include "../suse_linux/Makefile.common"
