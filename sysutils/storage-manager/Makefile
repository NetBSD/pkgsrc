# $NetBSD: Makefile,v 1.14 2005/06/17 03:50:35 jlam Exp $

DISTNAME=		sm_linux_v314_install
PKGNAME=		storage-manager-3.14
CATEGORIES=		sysutils
MASTER_SITES=		# empty
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://opensource.adaptec.com/
COMMENT=		Adaptec Storage Management software

BUILD_DEPENDS+=		rpm>=2.5.4:../../misc/rpm
DEPENDS+=		suse_compat>=6.1:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11

ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=			${WRKDIR}/sm_linux_v314_install
CHECK_SHLIBS=		NO
_STRIPFLAG_INSTALL=	# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined
INTERACTIVE_STAGE=	fetch

DOWNLOAD=		http://www.adaptec.com/worldwide/support/driverdetail.html?cat=%2fOperating+System%2fLinux&filekey=sm_linux_v314_install.rpm

_FETCH_MESSAGE= \
	${ECHO} "================================================================="; \
	${ECHO} "  Adaptec Storage Manager 3.14 for RedHat Linux must be fetched"; \
	${ECHO} "  into ${DISTDIR} from"; \
	${ECHO} "  ${DOWNLOAD}."; \
	${ECHO} "================================================================="

INSTALLATION_DIRS=	etc/rc.d sbin

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && rpm2cpio ${DISTDIR}/${DISTNAME}.rpm > ${DISTNAME}.cpio
	cd ${WRKSRC} && ${PAX} -O -d -rf ${DISTNAME}.cpio

do-patch:
	${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
		${FILESDIR}/dptmgr.sh > ${WRKDIR}/dptmgr.sh
	${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
		${FILESDIR}/dptsig.sh > ${WRKDIR}/dptsig.sh
	${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
		${FILESDIR}/raidutil.sh > ${WRKDIR}/raidutil.sh
	${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
		${FILESDIR}/dpteng > ${WRKDIR}/dpteng
	${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
		${FILESDIR}/dptelog > ${WRKDIR}/dptelog

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptcom ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptelog ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dpteng ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptmgr ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptscom ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptsig ${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/raidutil ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptcom.chk ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptelog.ini ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptmgr.hlp ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptmgr.rsc ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptmgr.ini ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/read.me ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.la ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.so ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.so.1 ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.so.1.0.2 ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.la ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.so ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.so.1 ${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.so.1.0.2 ${PREFIX}/lib/dpt
	${INSTALL_MAN} ${WRKSRC}/usr/local/man/man8/raidutil.8 ${PREFIX}/man/man8
	${INSTALL_SCRIPT} ${WRKDIR}/dptmgr.sh ${PREFIX}/sbin/dptmgr
	${INSTALL_SCRIPT} ${WRKDIR}/dptsig.sh ${PREFIX}/sbin/dptsig
	${INSTALL_SCRIPT} ${WRKDIR}/raidutil.sh ${PREFIX}/sbin/raidutil
	${INSTALL_SCRIPT} ${WRKDIR}/dpteng ${PREFIX}/etc/rc.d/dpteng
	${INSTALL_SCRIPT} ${WRKDIR}/dptelog ${PREFIX}/etc/rc.d/dptelog

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
