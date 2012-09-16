# $NetBSD: Makefile,v 1.16 2012/09/16 15:26:29 cheusov Exp $

DISTNAME=	lc	# overridden below
PKGNAME=	lc-${LCVER}
PKGREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://lc.cray.com/download/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://lc.cray.com/
COMMENT=	Finite Difference Time Domain (FDTD) Electromagnetic Simulator
LICENSE=		lc-license

CONFLICTS+=		mono-[0-9]* # bin/lc

RESTRICTED=		Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

PKG_DESTDIR_SUPPORT=	destdir

LCVER=			2.10
DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC= 		${WRKDIR}/lc${LCVER}
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		irix-mipsel irix-mipsel64
EMUL_PLATFORMS+=	linux-i386 linux-x86_64
EMUL_PLATFORMS+=	solaris-sparc
EMUL_MODULES.linux=	motif x11
EMUL_REQD=		suse>=9.1

.include "../../mk/bsd.prefs.mk"

DISTFILES=		lc_doc.tar.gz
.if ${EMUL_PLATFORM} == "linux-i386"
DISTFILES+=		lc_linux_motif3.tar.gz
.elif ${EMUL_PLATFORM} == "linux-x86_64"
DISTFILES+=		lc_amd64_lx24.tar.gz
.elif ${EMUL_PLATFORM} == "irix-mipsel"
DISTFILES+=		lc_irix.tar.gz
.elif ${EMUL_PLATFORM} == "irix-mipsel64"
DISTFILES+=		lc_irix64.tar.gz
.elif ${EMUL_PLATFORM} == "solaris-sparc"
DISTFILES+=		lc_solaris.tar.gz
.endif

PLIST_VARS+=		lcspice

.if ${EMUL_PLATFORM} == "linux-x86_64"
WRKSRC=			${WRKDIR}/lc
.else
PLIST.lcspice=		yes
.endif

INSTALLATION_DIRS=	bin share

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lc ${DESTDIR}${PREFIX}/bin/lc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lcplot ${DESTDIR}${PREFIX}/bin/lcplot
	if test -f ${WRKSRC}/bin/spice ; then ${INSTALL_PROGRAM} ${WRKSRC}/bin/spice ${DESTDIR}${PREFIX}/bin/lcspice ; fi
	# remove cat pages after extraction but before installation
	cd ${DESTDIR}${PREFIX}/share && \
	  ${TAR} -zxf ${DISTDIR}/${DIST_SUBDIR}/lc_doc.tar.gz && \
	  ${RM} -rf lc${LCVER}/man
	${CHMOD} -R ugo+rX ${DESTDIR}${PREFIX}/share/lc${LCVER}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/lc${LCVER}

.include "../../mk/bsd.pkg.mk"
