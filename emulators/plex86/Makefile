# $NetBSD: Makefile,v 1.25 2003/09/22 11:56:19 jmmv Exp $

DISTNAME=	plex86-20010106
PKGNAME=	${DISTNAME:S/-/-0./}
WRKSRC=		${WRKDIR}/plex86
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.plex86.org/
COMMENT=	Extensible open source PC virtualization software (free VMware)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-NetBSD \
		--with-netbsd-source=${BSDSRCDIR}/sys
USE_GMAKE=	yes
USE_X11BASE=	yes	# for VGA font

ONLY_FOR_PLATFORM= NetBSD-*-i386

RESTRICTED=	CPU-specific binary code
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

.include "../../mk/bsd.prefs.mk"

pre-extract:
.if !defined(BSDSRCDIR)
	@${ECHO_MSG} "Please set BSDSRCDIR in /etc/mk.conf, pointing it"
	@${ECHO_MSG} "to a directory that contains sources that match"
	@${ECHO_MSG} "your currently running system (esp. kernel), e.g."
	@${ECHO_MSG} "/usr/src."
	@${FALSE}
.endif
.if !exists(${BSDSRCDIR}/sys/sys/param.h)
	@${ECHO_MSG} "Need a kernel source tree in ${BSDSRCDIR}/sys."
	@${ECHO_MSG} "(Or set BSDSRCDIR correctly in /etc/mk.conf.)"
	@${FALSE}
.endif

post-build:
	${TEST} -f ${WRKSRC}/misc/vga.pcf.gz || \
	${GZIP_CMD} -9 ${WRKSRC}/misc/vga.pcf

do-install: do-install-dirs do-install-binaries do-install-bios \
		do-install-font do-install-conf

do-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}/lkm
	${INSTALL_DATA_DIR} ${PREFIX}/lib/plex86
	${INSTALL_DATA_DIR} ${PREFIX}/lib/plex86/bios
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/plex86

do-install-binaries:
	${INSTALL_PROGRAM} ${WRKSRC}/user/plex86 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/user/resetmod ${PREFIX}/bin/plex86_reset
	${INSTALL_DATA} ${WRKSRC}/user/plugins/bochs/plugin-bochs.so ${PREFIX}/lib/plex86
	${INSTALL_DATA} ${WRKSRC}/kernel/plex86.o ${PREFIX}/lkm
	${INSTALL_SCRIPT} ${WRKSRC}/misc/netbsd_post.sh ${PREFIX}/lib/plex86

do-install-bios:
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS* \
		${WRKSRC}/bios/VGABIOS-elpin-2.40 \
		${PREFIX}/lib/plex86/bios

do-install-font:
	${INSTALL_DATA} ${WRKSRC}/misc/vga.pcf.gz ${PREFIX}/lib/X11/fonts/local
	${X11BASE}/bin/mkfontdir ${PREFIX}/lib/X11/fonts/local

do-install-conf:
	@cd ${WRKSRC}/conf && for f in freedos linuxhd msdos qnx win95 winnt; do \
		${SED}	-e 's,\.\./\.\./,/PATH/TO/,' \
			-e 's,\.\./bios/,${PREFIX}/lib/plex86/bios/,' \
			-e 's,\./plugins/bochs/,${PREFIX}/lib/plex86/,' \
			$$f >${WRKDIR}/$$f.conf; \
	done
	${INSTALL_DATA} ${WRKDIR}/*.conf ${PREFIX}/share/examples/plex86

.include "../../mk/bsd.pkg.mk"
