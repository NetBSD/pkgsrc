# $NetBSD: Makefile,v 1.21 2005/06/17 03:50:24 jlam Exp $
#

# A default so lintpkgsrc is happy, overridden below
DISTNAME=       citrix
PKGNAME=	citrix_ica-7.00
CATEGORIES=	net
MASTER_SITES=	http://download2.citrix.com/files/en/products/client/ica/current/

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://www.citrix.com/products/clients/ica/technology.asp
COMMENT=	Citrix(R) client for the Microsoft Windows Terminal Server

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=      Linux-*-i[3-6]86 NetBSD-*-i386 NetBSD-*-sparc SunOS-*-sparc

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386"
DISTNAME=	linuxx86
PKGNAME=	citrix_ica-7.00.77757
.  elif ${MACHINE_ARCH} == "sparc"
DISTNAME=       solaris
PKGNAME=        citrix_ica-7.02.78662
EXTRACT_SUFX=   .tar.Z
.  endif
.elif ${OPSYS} == "SunOS"
DISTNAME=	solaris
PKGNAME=	citrix_ica-7.02.78662
EXTRACT_SUFX=	.tar.Z
.elif ${OPSYS} == "Linux"
DISTNAME=	linuxx86
PKGNAME=	citrix_ica-7.00.77757
.endif

# see http://www.citrix.com/download/unix-downloads.htm
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
DEPENDS=        suse_x11>=6.4:../../emulators/${SUSE_DIR_PREFIX}_x11
.endif

LICENSE=                citrix_ica-license
RESTRICTED=             License prohibits redistribution
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

WRKSRC=         ${WRKDIR}
DIST_SUBDIR=    ${PKGNAME}

CDIR=           ${PREFIX}/lib/ICAClient
BINDIR=         ${PREFIX}/bin

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON= "${PKGNAME} requires SVR4 compability - see compat_svr4(8)"
.  endif
.endif

INSTALLATION_DIRS=	bin

PATCHDIR=${WRKDIR}/.patches
pre-patch:
	${MKDIR} ${PATCHDIR}
	${CP} ${PKGDIR}/patches/patch-${MACHINE_ARCH}-* ${PATCHDIR}
	${CHMOD} -R u+w ${WRKSRC}

do-build:
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/response.${MACHINE_ARCH} \
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

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
.  include "../../emulators/suse_linux/Makefile.application"
.endif

.include "../../mk/bsd.pkg.mk"
