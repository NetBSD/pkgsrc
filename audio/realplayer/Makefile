# $NetBSD: Makefile,v 1.10 2002/07/02 11:28:30 agc Exp $

DISTNAME=		rp8_linux20_libc6_i386_cs2
PKGNAME=		realplayer-8.0.1
WRKSRC=			${WRKDIR}/RealPlayer8
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.bin

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.real.com/products/player/
COMMENT=		RealAudio and RealVideo player

DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

CRYPTO=			# defined
INTERACTIVE_STAGE=	fetch
CHECK_SHLIBS=		NO

XAUTHORITY?=		${HOME}/.Xauthority
.if exists(${XAUTHORITY})
EXTRACT_CMD=		HOME=${WRKDIR} XAUTHORITY=${XAUTHORITY} ${RP_INSTALLER}
.else
EXTRACT_CMD=		HOME=${WRKDIR} ${RP_INSTALLER}
.endif

DOWNLOAD=		http://proforma.real.com/real/player/unix/unix.html
RP_INSTALLER=		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer8
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins
MESSAGE_SUBST+=		REALPLAYER_HOME=${REALPLAYER_HOME}

_FETCH_MESSAGE= \
	    ${ECHO} "==============================================================="; \
	    ${ECHO} "  RealPlayer 8 for Linux 2.x (libc6 i386, Self-Extracting) must"; \
	    ${ECHO} "  be fetched into ${DISTDIR} from"; \
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
	cd ${WRKDIR}; ${PAX} -rw RealPlayer8 ${PREFIX}/lib

post-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/raclass.zip ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/rpnp.so ${NS_PLUGINS_DIR}

.include "../../emulators/suse_linux/Makefile.application"
