# $NetBSD: Makefile,v 1.6 2003/05/05 17:57:35 grant Exp $

DISTNAME=	vmware-netbsd-3.2.2
PKGNAME=	vmware-module-3.2.2
WRKSRC=		${WRKDIR}
CATEGORIES=	emulators
MASTER_SITES=   ftp://ftp.netbsd.org/pub/NetBSD/misc/vmware/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.wasabisystems.com/
COMMENT=	Kernel modules for the VMware 3.x emulator

CONFLICTS=	vmware-module-1.*

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CONFIGURE=	# defined

NO_SRC_ON_FTP=		already there

# to override <bsd.own.mk>, MUST be set this way BEFORE bsd.prefs.mk
BSDSRCDIR?=	/nonexistent

.include "../../mk/bsd.prefs.mk"

pre-extract:
.if ${BSDSRCDIR} == "/nonexistent"
	@${ECHO_MSG} "Please set BSDSRCDIR in /etc/mk.conf, pointing it"
	@${ECHO_MSG} "to a directory that contains sources that match"
	@${ECHO_MSG} "your currently running system (esp. kernel), e.g."
	@${ECHO_MSG} "/usr/src."
	@${FALSE}
.endif
.if !exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
	@${ECHO_MSG} "Need a kernel source tree in ${BSDSRCDIR}/sys."
	@${ECHO_MSG} "(Or set BSDSRCDIR correctly in /etc/mk.conf.)"
	@${FALSE}
.endif

do-build:
.for dir in linuxrtc vmmon vmnet
	cd ${WRKSRC}/source/${dir} && ${MAKE}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lkm
	${INSTALL_DATA_DIR} ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/linuxrtc ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/vmmon ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/vmnet ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/vmnetif ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/source/linuxrtc/linuxrtc.o ${PREFIX}/lkm
	${INSTALL_DATA} ${WRKDIR}/source/vmmon/vmmon.o ${PREFIX}/lkm
	${INSTALL_DATA} ${WRKDIR}/source/vmnet/vmnet.o ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKDIR}/share/lkm/vmnet_post.sh ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKDIR}/share/lkm/linuxrtc_post.sh ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKDIR}/share/lkm/vmmon_post.sh ${PREFIX}/lkm
	@cd ${WRKSRC}/rc.d && for f in linuxrtc vmmon vmnet vmnetif; do \
		${SED}  -e 's,@PREFIX@,${PREFIX},' < $$f > $$f.patched; \
		${INSTALL_SCRIPT} $$f.patched ${PREFIX}/etc/rc.d/$$f; \
	done
	${SED} -e 's,@VMWARE_PREFIX@,${PREFIX},' \
		< ${WRKSRC}/rc.conf.d/vmware > ${WRKSRC}/rc.conf.d/vmware.patched
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmware.patched \
		${PREFIX}/etc/rc.conf.d/vmware

post-install:
	PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles
