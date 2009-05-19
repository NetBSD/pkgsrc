# $NetBSD: Makefile,v 1.26 2009/05/19 08:59:35 wiz Exp $

DISTNAME=		sm_linux_v314_install
PKGNAME=		storage-manager-3.14
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		# empty
EXTRACT_SUFX=		.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://opensource.adaptec.com/
COMMENT=		Adaptec Storage Management software
LICENSE=		generic-nonlicense

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

BUILD_DEPENDS+=		rpm>=2.5.4:../../misc/rpm

USE_TOOLS+=	pax

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	compat x11

WRKSRC=			${WRKDIR}/sm_linux_v314_install
INTERACTIVE_STAGE=	fetch
_STRIPFLAG_INSTALL=	# defined
BUILD_DIRS=		# empty

DOWNLOAD=		http://www.adaptec.com/worldwide/support/driverdetail.html?cat=%2fOperating+System%2fLinux&filekey=sm_linux_v314_install.rpm

FETCH_MESSAGE=								\
	"Adaptec Storage Manager 3.14 for RedHat Linux must be fetched"	\
	"into:"								\
	"    ${DISTDIR}"						\
	"from"								\
	"    ${DOWNLOAD}"

INSTALLATION_DIRS=	etc/rc.d sbin

do-extract:
	${MKDIR} ${WRKSRC}
	cd ${WRKSRC} && rpm2cpio ${DISTDIR}/${DISTNAME}.rpm > ${DISTNAME}.cpio
	cd ${WRKSRC} && pax -O -d -rf ${DISTNAME}.cpio

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
	${INSTALL_MAN} ${WRKSRC}/usr/local/man/man8/raidutil.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_SCRIPT} ${WRKDIR}/dptmgr.sh ${PREFIX}/sbin/dptmgr
	${INSTALL_SCRIPT} ${WRKDIR}/dptsig.sh ${PREFIX}/sbin/dptsig
	${INSTALL_SCRIPT} ${WRKDIR}/raidutil.sh ${PREFIX}/sbin/raidutil
	${INSTALL_SCRIPT} ${WRKDIR}/dpteng ${PREFIX}/etc/rc.d/dpteng
	${INSTALL_SCRIPT} ${WRKDIR}/dptelog ${PREFIX}/etc/rc.d/dptelog

.include "../../mk/bsd.pkg.mk"
