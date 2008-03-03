# $NetBSD: Makefile,v 1.12 2008/03/03 01:43:01 jlam Exp $

DISTNAME=	lc	# overridden below
PKGNAME=	lc-2.10
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://lc.cray.com/download/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://lc.cray.com/
COMMENT=	Finite Difference Time Domain (FDTD) Electromagnetic Simulator

DIST_SUBDIR=	${PKGNAME_NOREV}

RESTRICTED=		Original installer required to redistribute.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
LICENSE=		lc-license

PKG_DESTDIR_SUPPORT=	destdir

WRKSRC=			${WRKDIR}/lc2.10
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

.if ${EMUL_PLATFORM} == "linux-x86_64"
WRKSRC=			${WRKDIR}/lc
PLIST_SUBST+=		HAVE_LCSPICE="@comment "
.else
PLIST_SUBST+=		HAVE_LCSPICE=""
.endif

INSTALLATION_DIRS=	bin share

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lc ${DESTDIR}${PREFIX}/bin/lc
	${INSTALL_PROGRAM} ${WRKSRC}/bin/lcplot ${DESTDIR}${PREFIX}/bin/lcplot
	if test -f ${WRKSRC}/bin/spice ; then ${INSTALL_PROGRAM} ${WRKSRC}/bin/spice ${DESTDIR}${PREFIX}/bin/lcspice ; fi
	cd ${DESTDIR}${PREFIX}/share && ${TAR} -zxf ${DISTDIR}/${DIST_SUBDIR}/lc_doc.tar.gz
	${CHMOD} -R ugo+rX ${DESTDIR}${PREFIX}/share/lc2.10
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/lc2.10

.include "../../mk/bsd.pkg.mk"
