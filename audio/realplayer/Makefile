# $NetBSD: Makefile,v 1.22 2003/11/15 00:20:28 dmcmahill Exp $

PKGNAME=		realplayer-8.0.1
WRKSRC=			${WRKDIR}/RealPlayer8
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.bin

.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
DISTNAME=		rp8_linux20_libc6_i386_cs2
.elif ${MACHINE_ARCH} == "sparc"
DISTNAME=		rp8_solaris27_sparc_cs2
.else
DISTNAME=		must_be_defined
.endif

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.real.com/products/player/
COMMENT=		RealAudio and RealVideo player

.if ${OPSYS} == "NetBSD"
. if ${MACHINE_ARCH} == "i386"
DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11
. elif ${MACHINE_ARCH} == "sparc"
.  if !exists(/emul/svr4/usr/lib/ld.so)
PKG_FAIL_REASON= "${PKGNAME} requires Solaris libraries - see compat_svr4(8)"
.  endif
. endif
.endif

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-sparc SunOS-*-sparc

CONFLICTS=		realplayer-codecs<8nb2

CRYPTO=			# defined
INTERACTIVE_STAGE=	fetch extract
CHECK_SHLIBS=		NO

XAUTHORITY?=		${HOME}/.Xauthority
.if exists(${XAUTHORITY})
EXTRACT_CMD=		HOME=${WRKDIR} XAUTHORITY=${XAUTHORITY} ${RP_INSTALLER}
.else
EXTRACT_CMD=		HOME=${WRKDIR} ${RP_INSTALLER}
.endif

DOWNLOAD=		http://forms.real.com/real/player/unix/unix.html
RP_INSTALLER=		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer8
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins
MESSAGE_SUBST+=		REALPLAYER_HOME=${REALPLAYER_HOME}

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "  RealPlayer 8 (Self-Extracting) must be fetched"; \
	    ${ECHO} "  into ${DISTDIR} from"; \
	    ${ECHO} "  ${DOWNLOAD}."; \
	    ${ECHO} "==============================================================="

pre-extract:
	@delay=15;							\
	${SED}	-e "s|@WRKSRC@|${WRKSRC}|g"				\
		-e "s|@delay@|$${delay}|g"				\
		${FILESDIR}/extract_instructions;			\
	sleep $${delay}
	@if [ ! -x ${RP_INSTALLER} ]; then				\
		${CHMOD} +x ${RP_INSTALLER};				\
	fi

do-build:
	cd ${WRKSRC};							\
		${MV} -f mimeinstall.sh mimeinstall.sh.old;		\
		${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
			-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g"	\
			mimeinstall.sh.old > mimeinstall.sh;		\
		${CHMOD} +x mimeinstall.sh
	${SED}	-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g"		\
		${FILESDIR}/realplay.sh > ${WRKDIR}/realplay.sh

pre-install:
	${FIND} ${WRKSRC} \( -name "*.orig" -o -name "*.old" \) -print	\
		| ${XARGS} ${RM}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplay.sh ${PREFIX}/bin/realplay
	cd ${WRKDIR} && ${PAX} -rw RealPlayer8 ${PREFIX}/lib

post-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/raclass.zip ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/rpnp.so ${NS_PLUGINS_DIR}

.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "i386"
.include "../../emulators/suse_linux/Makefile.application"
.endif
.include "../../mk/bsd.pkg.mk"
