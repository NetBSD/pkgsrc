# $NetBSD: Makefile,v 1.3 2002/02/26 21:28:48 fredb Exp $

DISTNAME=	vmware-netbsd-1.0
PKGNAME=	vmware-module-1.0
CATEGORIES=	emulators
MASTER_SITES=   # empty
EXTRACT_SUFX=	.tgz

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.wasabisystems.com/
COMMENT=	Kernel modules for the VMware emulator

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	# defined

NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DOWNLOAD=	http://www.wasabisystems.com/vmware-survey.html

_FETCH_MESSAGE=	\
	${ECHO} "==============================================================="; \
	${ECHO} "  The VMware kernel module must be fetched into \"${DISTDIR}\""; \
	${ECHO} "  via the Web formular available under this URL:"; \
	${ECHO} "  ${DOWNLOAD}"; \
	${ECHO} "==============================================================="

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${_FETCH_MESSAGE}; \
	    ${FALSE}; \
	fi

fetch-list-one-pkg:
	@${ECHO} ${_FETCH_MESSAGE:Q}

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
	for dirs in linuxrtc vmmon vmnet; do \
		cd ${WRKSRC}/source/$${dirs} && ${MAKE}; \
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lkm ${PREFIX}/etc/rc.conf.d
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/linuxrtc ${PREFIX}/etc/rc.conf.d/
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/vmmon ${PREFIX}/etc/rc.conf.d/
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/vmnet ${PREFIX}/etc/rc.conf.d/
	${INSTALL_DATA} ${WRKDIR}/rc.conf.d/vmnetif ${PREFIX}/etc/rc.conf.d/
	${INSTALL_DATA} ${WRKDIR}/source/linuxrtc/linuxrtc.o ${PREFIX}/lkm/
	${INSTALL_DATA} ${WRKDIR}/source/vmmon/vmmon.o ${PREFIX}/lkm/
	${INSTALL_DATA} ${WRKDIR}/source/vmnet/if_hub.o ${PREFIX}/lkm/
	${INSTALL_SCRIPT} ${WRKDIR}/share/lkm/if_hub_post.sh ${PREFIX}/lkm/
	${INSTALL_SCRIPT} ${WRKDIR}/share/lkm/linuxrtc_post.sh ${PREFIX}/lkm/
	${INSTALL_SCRIPT} ${WRKDIR}/share/lkm/vmmon_post.sh ${PREFIX}/lkm/
	@cd ${WRKSRC}/rc.d && for f in linuxrtc vmmon vmnet vmnetif; do \
		${SED}  -e 's,@PREFIX@,${PREFIX},' < $$f > $$f.patched; \
		${INSTALL_SCRIPT} $$f.patched ${PREFIX}/etc/rc.d/$$f; \
	done
	${SED}  -e 's,@VMWARE_PREFIX@,${PREFIX},' \
		< ${WRKSRC}/rc.conf.d/vmware > ${WRKSRC}/rc.conf.d/vmware.patched
	${INSTALL_DATA} ${WRKSRC}/rc.conf.d/vmware.patched \
		${PREFIX}/etc/rc.conf.d/vmware

post-install:
	PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

.include "../../mk/bsd.pkg.mk"

LDFLAGS=	# empty since we use BSD-style makefiles
