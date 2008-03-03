# $NetBSD: Makefile,v 1.24 2008/03/03 19:21:38 jlam Exp $

DISTNAME=	vmware-netbsd-3.2.1.8
PKGNAME=	vmware-module-3.2.1.8
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vmware/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://www.wasabisystems.com/
COMMENT=	Kernel modules for the VMware 3.2.1 PC emulator

CONFLICTS=	vmware-module-1.*

ONLY_FOR_PLATFORM=	NetBSD-*-i386

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

NO_SRC_ON_FTP=		already there

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS= etc/rc.conf.d etc/rc.d lkm

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
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/linuxrtc \
		${DESTDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmmon \
		${DESTDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmnet \
		${DESTDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmnetif \
		${DESTDIR}${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKSRC}/source/linuxrtc/linuxrtc.o \
		${DESTDIR}${PREFIX}/lkm
	${INSTALL_DATA} ${WRKSRC}/source/vmmon/vmmon.o \
		${DESTDIR}${PREFIX}/lkm
	${INSTALL_DATA} ${WRKSRC}/source/vmnet/vmnet.o \
		${DESTDIR}${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/share/lkm/vmnet_post.sh \
		${DESTDIR}${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/share/lkm/linuxrtc_post.sh \
		${DESTDIR}${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/share/lkm/vmmon_post.sh \
		${DESTDIR}${PREFIX}/lkm
	@cd ${WRKSRC}/rc.d && for f in linuxrtc vmmon vmnet vmnetif; do \
		${SED}  -e 's,@PREFIX@,${PREFIX},' < $$f > $$f.patched; \
		${INSTALL_SCRIPT} $$f.patched ${DESTDIR}${PREFIX}/etc/rc.d/$$f; \
	done
	${SED} -e 's,@VMWARE_PREFIX@,${PREFIX},' \
		< ${WRKSRC}/rc.conf.d/vmware > ${WRKSRC}/rc.conf.d/vmware.patched
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmware.patched \
		${DESTDIR}${PREFIX}/etc/rc.conf.d/vmware

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles
