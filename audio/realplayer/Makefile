# $NetBSD: Makefile,v 1.1.1.1 2000/12/25 09:35:58 jlam Exp $

DISTNAME=		rp8_linux20_libc6_i386_cs1
PKGNAME=		realplayer-8
WRKSRC=			${WRKDIR}/RealPlayer8
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.bin

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.real.com/products/player/

DEPENDS+=		suse_x11>=6.1:../../emulators/suse_x11

RESTRICTED=		"Redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

CRYPTO=			# defined
IS_INTERACTIVE=		# defined
CHECK_SHLIBS=		NO

XAUTHORITY?=		${HOME}/.Xauthority
.if exists(${XAUTHORITY})
EXTRACT_CMD=		HOME=${WRKDIR} XAUTHORITY=${XAUTHORITY} ${RP_INSTALLER}
.else
EXTRACT_CMD=		HOME=${WRKDIR} ${RP_INSTALLER}
.endif

NO_CONFIGURE=		# defined
SCRIPTS_ENV+=		CAT="${CAT}"
SCRIPTS_ENV+=		CHMOD="${CHMOD}"
SCRIPTS_ENV+=		RP_INSTALLER="${RP_INSTALLER}"
MESSAGE_FILE=		${WRKDIR}/MESSAGE

DOWNLOAD=		http://proforma.real.com/real/player/unix/unix.html
RP_INSTALLER=		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer8
NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-fetch:
	@if [ ! -f ${RP_INSTALLER} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  RealPlayer 8 for Linux 2.x (libc6 i386, Self-Extracting) must"; \
	    ${ECHO_MSG} "  be fetched into ${DISTDIR} from"; \
	    ${ECHO_MSG} "  ${DOWNLOAD}."; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

# scripts/pre-extract

do-build:
	cd ${WRKSRC};							\
		${MV} -f mimeinstall.sh mimeinstall.sh.old;		\
		${SED}	-e "s,@PREFIX@,${PREFIX},g"			\
			-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g"	\
			< mimeinstall.sh.old > mimeinstall.sh;		\
		${CHMOD} +x mimeinstall.sh
	${SED}	-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g" \
		< ${FILESDIR}/realplay.sh > ${WRKDIR}/realplay.sh

pre-install:
	${FIND} ${WRKSRC} \
		\( -name "*.orig" -o -name "*.old" \) -exec ${RM} {} \;
	${SED}	-e "s,@REALPLAYER_HOME@,${REALPLAYER_HOME},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplay.sh ${PREFIX}/bin/realplay
	cd ${WRKDIR}; ${PAX} -rw RealPlayer8 ${PREFIX}/lib

post-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/raclass.zip ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/rpnp.so ${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
