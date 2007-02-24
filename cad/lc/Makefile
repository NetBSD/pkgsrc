# $NetBSD: Makefile,v 1.9 2007/02/24 03:43:49 dmcmahill Exp $

DISTNAME=	lc	# Overridden below
PKGNAME=	lc-2.10
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://lc.cray.com/download/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://lc.cray.com/
COMMENT=	Finite Difference Time Domain (FDTD) Electromagnetic Simulator

DIST_SUBDIR=	${PKGNAME_NOREV}

RESTRICTED=	Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
LICENSE=		lc-license
CHECK_SHLIBS_SUPPORTED=	no

WRKSRC=		${WRKDIR}/lc2.10
NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

# With this, we can run
#  make makesum MAINTAINER_MODE=yes
# and process all the possible distfiles without regard to what platform we're on
.if defined(MAINTAINER_MODE)
DISTFILES=	lc_doc.tar.gz
DISTFILES+=	lc_amd64_lx24.tar.gz
DISTFILES+=	lc_irix.tar.gz
DISTFILES+=	lc_irix64.tar.gz
DISTFILES+=	lc_linux_motif1.tar.gz
DISTFILES+=	lc_linux_motif3.tar.gz
DISTFILES+=	lc_solaris.tar.gz

.else


ONLY_FOR_PLATFORM=	*-*-i386 *-*-mipsel *-*-mipsel64
ONLY_FOR_PLATFORM+=	*-*-sparc *-*-sparc64 *-*-x86_64

.if (${MACHINE_ARCH} == "x86_64")
DISTNAME=	lc_amd64_lx24
. if (${OPSYS} == "NetBSD")
DEPENDS+=	suse_openmotif>=9.1:../../emulators/${SUSE_DIR_PREFIX}_openmotif
DEPENDS+=	suse_x11>=9.1:../../emulators/${SUSE_DIR_PREFIX}_x11
. endif
WRKSRC=		${WRKDIR}/lc
HAVE_LCSPICE=	"@comment "

.elif ${MACHINE_ARCH} == "mipsel"
DISTNAME=	lc_irix

.elif ${MACHINE_ARCH} == "mipsel64"
DISTNAME=	lc_irix64

.elif (${MACHINE_ARCH} == "i386")
#DISTNAME=	lc_linux_motif1
DISTNAME=	lc_linux_motif3
. if (${OPSYS} == "NetBSD")
DEPENDS+=	suse_openmotif>=9.1:../../emulators/${SUSE_DIR_PREFIX}_openmotif
DEPENDS+=	suse_x11>=9.1:../../emulators/${SUSE_DIR_PREFIX}_x11
. endif

.elif ${MACHINE_ARCH} == "sparc" || ${MACHINE_ARCH} == "sparc64"
DISTNAME=	lc_solaris
. if (${OPSYS} == "NetBSD")
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON+= '${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.  endif
. endif
.endif

HAVE_LCSPICE?=	""

PLIST_SUBST+=	HAVE_LCSPICE=${HAVE_LCSPICE}

DISTFILES=	lc_doc.tar.gz ${DISTNAME}${EXTRACT_SUFX}

INSTALLATION_DIRS=	bin share

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lc ${PREFIX}/bin/lc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lcplot ${PREFIX}/bin/lcplot
	if test -f ${WRKSRC}/bin/spice ; then ${INSTALL_PROGRAM} ${WRKSRC}/bin/spice ${PREFIX}/bin/lcspice ; fi
	cd ${PREFIX}/share && ${TAR} -zxf ${DISTDIR}/${DIST_SUBDIR}/lc_doc.tar.gz
	${CHMOD} -R 644 ${PREFIX}/share/lc2.10
	${CHOWN} -R ${SHAREOWN} ${PREFIX}/share/lc2.10
	${CHGRP} -R ${SHAREGRP} ${PREFIX}/share/lc2.10

.endif # !MAINTAINER

# do not include the linux stuff if we are, for example, on a Solaris box
. if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
