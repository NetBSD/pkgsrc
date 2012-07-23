# $NetBSD: Makefile,v 1.30 2012/07/23 22:20:16 jnemeth Exp $

DISTNAME=		sm_linux_v314_install
PKGNAME=		storage-manager-3.14
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		# empty
EXTRACT_SUFX=		.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://opensource.adaptec.com/
COMMENT=		Adaptec Storage Management software
LICENSE=		generic-nonlicense

PKG_DESTDIR_SUPPORT=	user-destdir

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

DOWNLOAD=		http://www.adaptec.com/en-us/speed/raid/aar/unix/sm_linux_v314_install_aar.htm

FETCH_MESSAGE=								\
	"Adaptec Storage Manager 3.14 for RedHat Linux must be fetched"	\
	"into:"								\
	"    ${DISTDIR}"						\
	"from"								\
	"    ${DOWNLOAD}"

INSTALLATION_DIRS=	etc/rc.d sbin lib/dpt man/man8

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
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptcom ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptelog ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dpteng ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptmgr ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptscom ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/dptsig ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_PROGRAM} ${WRKSRC}/usr/dpt/raidutil ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptcom.chk ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptelog.ini ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptmgr.hlp ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptmgr.rsc ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/dptmgr.ini ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/dpt/read.me ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.la ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.so ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.so.1 ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libMrm.so.1.0.2 ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.la ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.so ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.so.1 ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_DATA} ${WRKSRC}/usr/local/LessTif/Motif1.2/lib/libXm.so.1.0.2 ${DESTDIR}${PREFIX}/lib/dpt
	${INSTALL_MAN} ${WRKSRC}/usr/local/man/man8/raidutil.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_SCRIPT} ${WRKDIR}/dptmgr.sh ${DESTDIR}${PREFIX}/sbin/dptmgr
	${INSTALL_SCRIPT} ${WRKDIR}/dptsig.sh ${DESTDIR}${PREFIX}/sbin/dptsig
	${INSTALL_SCRIPT} ${WRKDIR}/raidutil.sh ${DESTDIR}${PREFIX}/sbin/raidutil
	${INSTALL_SCRIPT} ${WRKDIR}/dpteng ${DESTDIR}${PREFIX}/etc/rc.d/dpteng
	${INSTALL_SCRIPT} ${WRKDIR}/dptelog ${DESTDIR}${PREFIX}/etc/rc.d/dptelog

.include "../../mk/bsd.pkg.mk"
