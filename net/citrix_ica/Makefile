# $NetBSD: Makefile,v 1.12 2002/11/26 21:43:49 cjep Exp $
#

# A default so lintpkgsrc is happy
PKGNAME=	citrix_ica-6.30
DISTNAME=       citrix
.if (${MACHINE_ARCH} == "i386")
DISTNAME=	linuxx86
PKGNAME=	citrix_ica-6.30.1050
.endif
.if (${MACHINE_ARCH} == "sparc")
DISTNAME=       solaris
PKGNAME=        citrix_ica-6.20.985
EXTRACT_SUFX=   .tar.Z
.endif
CATEGORIES=	net
MASTER_SITES=	http://download2.citrix.com/files/en/products/client/ica/current/

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://www.citrix.com/products/clients/ica/technology.asp
COMMENT=	Citrix(R) client for the Microsoft Windows Terminal Server

.if (${MACHINE_ARCH} == "i386")
DEPENDS=        suse_x11>=6.4:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-sparc

# see http://www.citrix.com/download/unix-downloads.htm
LICENSE=                citrix_ica-license
RESTRICTED=             License prohibits redistribution
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

PLIST_SRC=	${PKGDIR}/PLIST.pre \
		${PKGDIR}/PLIST.${MACHINE_ARCH} \
		${PKGDIR}/PLIST.post

DIST_SUBDIR=    ${PKGNAME}
WRKSRC=         ${WRKDIR}

CDIR=           ${PREFIX}/lib/ICAClient
BINDIR=         ${PREFIX}/bin

.if (${MACHINE_ARCH} == "sparc")
.if !exists(/emul/svr4/usr/lib/ld.so)
IGNORE=         "${PKGNAME} requires SVR4 compability - see compat_svr4(8)"
.endif
.endif

PATCHDIR=${WRKDIR}/.patches
pre-patch:
	${MKDIR} ${PATCHDIR}
	${CP} ${PKGDIR}/patches/patch-${MACHINE_ARCH}-* ${PATCHDIR}

do-build:
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/response \
		> ${WRKSRC}/response
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x

pre-install:
	@if [ -d "${CDIR}" ]; then                                      \
		${ECHO} "";                                             \
		${ECHO} "*** Please remove ${CDIR} and try again ***";  \
		${ECHO} "";                                             \
		${FALSE};                                               \
	fi

do-install:
	cd ${WRKSRC} && ./setupwfc < response
	${INSTALL_SCRIPT} ${WRKSRC}/wfcmgr.x ${PREFIX}/bin/wfcmgr
	${INSTALL_SCRIPT} ${WRKSRC}/wfica.x ${PREFIX}/bin/wfica
	${SED} "s#/usr/lib/ICAClient#${CDIR}#g" \
		< ${CDIR}/util/icalicense.sh > ${CDIR}/util/icalicense.sh.fixed
	${MV} ${CDIR}/util/icalicense.sh.fixed ${CDIR}/util/icalicense.sh

.if (${MACHINE_ARCH} == "i386")
.include "../../emulators/suse_linux/Makefile.application"
.else
.include "../../mk/bsd.pkg.mk"
.endif
