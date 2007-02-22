# $NetBSD: Makefile,v 1.8 2007/02/22 19:26:28 wiz Exp $

DISTNAME=		suse_vmware-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package to support running VMware

DEPENDS+=		suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse91_base
DEPENDS+=	suse_x11-${SUSE_VERSION}{,nb*}:../../emulators/suse91_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

RPMFILES=		grep-2.5.1-416.i586.rpm
RPMIGNOREPATH=		usr

post-install:
	@${GREP} -v '^#' ${FILESDIR}/device-links | \
	${AWK} '{print("${LN} -fs "$$1" ${EMULDIR}/dev/"$$2)}' | \
	${SH} -
	@${GREP} -v '^#' ${FILESDIR}/device-links | \
	${AWK} '{print("@exec ${LN} -fs "$$1" %D/${EMULSUBDIR}/dev/"$$2)}' \
	  >>${PLIST_SRC}
	@${GREP} -v '^#' ${FILESDIR}/device-links | \
	${AWK} '{print("@unexec ${RM} -f %D/${EMULSUBDIR}/dev/"$$2)}' \
	  >>${PLIST_SRC}

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
