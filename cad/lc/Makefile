# $NetBSD: Makefile,v 1.1.1.1 2007/02/23 22:50:40 dmcmahill Exp $

DISTNAME=	lc	# Overridden below
PKGNAME=	lc-2.10
CATEGORIES=	cad
MASTER_SITES=	http://lc.cray.com/download/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://lc.cray.com/
COMMENT=	Finite Difference Time Domain (FDTD) Electromagnetic Simulator

DIST_SUBDIR=	${PKGNAME_NOREV}

# FIXME -- find the license and read it
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

ONLY_FOR_PLATFORM=	*-*-i386 *-*-sparc

.if (${MACHINE_ARCH} == "x86_64")
DISTNAME=	lc_amd64_lx24

.elif ${MACHINE_ARCH} == "mipsel"
DISTNAME=	lc_irix

.elif ${MACHINE_ARCH} == "mipsel64"
DISTNAME=	lc_irix64

.elif (${MACHINE_ARCH} == "i386")
#DISTNAME=	lc_linux_motif1
DISTNAME=	lc_linux_motif3
. if (${OPSYS} == "NetBSD")
DEPENDS+=	suse_gtk2>=9.1:../../emulators/${SUSE_DIR_PREFIX}_gtk2
. endif

.elif ${MACHINE_ARCH} == "sparc"
DISTNAME=	lc_solaris
. if (${OPSYS} == "NetBSD")
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON+= '${PKGNAME} requires Solaris libraries - see compat_svr4(8)'
.  endif
. endif
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lc ${PREFIX}/bin/lc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lcplot ${PREFIX}/bin/lcplot
	${INSTALL_PROGRAM} ${WRKSRC}/bin/spice ${PREFIX}/bin/lcspice

.endif # !MAINTAINER

# do not include the linux stuff if we are, for example, on a Solaris box
. if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
