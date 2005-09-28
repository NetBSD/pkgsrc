# $NetBSD: Makefile,v 1.18 2005/09/28 20:52:21 rillig Exp $

DISTNAME=	vmware-netbsd-3.2.1.7
PKGNAME=	vmware-module-3.2.1.7
CATEGORIES=	emulators
MASTER_SITES=   ftp://ftp.NetBSD.org/pub/NetBSD/misc/vmware/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.wasabisystems.com/
COMMENT=	Kernel modules for the VMware 3.2.1 PC emulator

CONFLICTS=	vmware-module-1.*

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_CONFIGURE=	yes

NO_SRC_ON_FTP=		already there

.include "../../mk/bsd.prefs.mk"

pre-extract:
.if !exists(${BSDSRCDIR}/sys/lib/libkern/libkern.h)
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
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/linuxrtc ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmmon ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmnet ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmnetif ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/source/linuxrtc/linuxrtc.o ${PREFIX}/lkm
	${INSTALL_DATA} ${WRKSRC}/source/vmmon/vmmon.o ${PREFIX}/lkm
	${INSTALL_DATA} ${WRKSRC}/source/vmnet/vmnet.o ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/share/lkm/vmnet_post.sh ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/share/lkm/linuxrtc_post.sh ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/share/lkm/vmmon_post.sh ${PREFIX}/lkm
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
