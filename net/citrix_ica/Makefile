# $NetBSD: Makefile,v 1.35 2007/07/03 13:31:31 sborrill Exp $
#

# A default so lintpkgsrc is happy, overridden below
DISTNAME=	citrix
PKGNAME=	citrix_ica-10.6.115659
CATEGORIES=	net
MASTER_SITES=	http://download2.citrix.com/FILES/en/products/Linux10/

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://www.citrix.com/English/SS/downloads/downloads.asp?dID=2755
COMMENT=	Citrix(R) ICA client for the Citrix(R) Presentation Server(TM)

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	Linux-*-i[3-6]86 NetBSD-*-i386 NetBSD-*-sparc SunOS-*-sparc
ONLY_FOR_PLATFORM+=	DragonFly-*-i386

.if ${OPSYS} == "NetBSD"
.  if ${MACHINE_ARCH} == "i386"
DISTNAME=	en.linuxx86
PKGNAME=	citrix_ica-10.6.115659
.  elif ${MACHINE_ARCH} == "sparc"
DISTNAME=	en.solaris
PKGNAME=	citrix_ica-8.46.110465
MASTER_SITES=	http://www.citrix.com/site/resources/dynamic/software/
EXTRACT_SUFX=	.tar.Z
.  endif
.elif ${OPSYS} == "SunOS"
DISTNAME=	en.solaris
PKGNAME=	citrix_ica-8.46.110465
MASTER_SITES=	http://www.citrix.com/site/resources/dynamic/software/
EXTRACT_SUFX=	.tar.Z
.elif ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly"
DISTNAME=	en.linuxx86
PKGNAME=	citrix_ica-10.0.110003
.endif

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly") && ${MACHINE_ARCH} == "i386"
DEPENDS+=        suse_x11>=6.4:../../emulators/${SUSE_DIR_PREFIX}_x11
DEPENDS+=        suse_openmotif>=6.4:../../emulators/${SUSE_DIR_PREFIX}_openmotif
DEPENDS+=        suse_locale>=6.4:../../emulators/${SUSE_DIR_PREFIX}_locale
.endif

LICENSE=		citrix_ica-license
RESTRICTED=		License prohibits redistribution
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGNAME_NOREV}

CDIR=		${PREFIX}/lib/ICAClient
USE_TOOLS+=	patch

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "sparc"
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON+=	"${PKGNAME} requires SVR4 compability - see compat_svr4(8)"
.  endif
.endif

INSTALLATION_DIRS=	bin

do-patch:
	(cd ${WRKSRC}; \
	for f in ${PATCHDIR}/patch-${MACHINE_ARCH}-*;do \
	${PATCH} ${PATCH_ARGS} <$$f >/dev/null 2>&1 || ${TRUE}; \
	done)

do-build:
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/response.${MACHINE_ARCH} \
		> ${WRKSRC}/response
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/wfcmgr \
		> ${WRKSRC}/wfcmgr.x
	${SED} s%DESTINATION%${CDIR}% ${FILESDIR}/wfica \
		> ${WRKSRC}/wfica.x

pre-install:
	if [ -d "${CDIR}" ]; then                                      \
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

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly") && ${MACHINE_ARCH} == "i386"
.  include "../../emulators/suse_linux/Makefile.application"
.endif

.include "../../mk/bsd.pkg.mk"
