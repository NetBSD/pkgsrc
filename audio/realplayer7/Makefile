# $NetBSD: Makefile,v 1.7 2000/08/18 22:46:30 hubertf Exp $
#

DISTNAME=		rp7_linux20_libc6_i386_cs1
PKGNAME=		realplayer-7nb3
WRKSRC=			${WRKDIR}/RealPlayer7
CATEGORIES=		audio
MASTER_SITES=		# empty
EXTRACT_SUFX=		.bin

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.real.com/products/player/

DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux

RESTRICTED=		"Export-controlled, redistribution not permitted"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

ONLY_FOR_PLATFORM=	NetBSD-*-i386

IS_INTERACTIVE=		yes
NO_CONFIGURE=		yes
RP_INSTALLER=		${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}
EXTRACT_CMD=		HOME=${WRKDIR} ${RP_INSTALLER}
XAUTHORITY?=		${HOME}/.Xauthority
.if exists(${XAUTHORITY})
EXTRACT_CMD=		HOME=${WRKDIR} XAUTHORITY=${XAUTHORITY} ${RP_INSTALLER}
.else
EXTRACT_CMD=		HOME=${WRKDIR} ${RP_INSTALLER}
.endif

DOWNLOAD=		http://proforma.real.com/real/player/unix/unix.html
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer7

NS_PLUGINS_DIR=		${PREFIX}/lib/netscape/plugins

do-fetch:
	@if [ ! -f ${RP_INSTALLER} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  RealPlayer 7 for Linux 2.x (libc6 i386, Self-Extracting) must"; \
	    ${ECHO_MSG} "  be fetched into ${DISTDIR} from"; \
	    ${ECHO_MSG} "  ${DOWNLOAD}."; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

pre-extract:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} " Now running the RealPlayer7 installation script.      "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Please choose 'Accept', then make sure the destination"
	@${ECHO_MSG} " directory is ${WRKSRC}"
	@${ECHO_MSG} " (it should be the first or second choice on the       "
	@${ECHO_MSG} " drop-down menu), then press Finish.                   "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Then cancel and exit out of the plugin install, and   "
	@${ECHO_MSG} " register if you choose to, otherwise cancel and exit. "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " After the introductory clip runs, exit RealPlayer     "
	@${ECHO_MSG} " to continue the package installation.                 "
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} ""
	@${CHMOD} +x ${RP_INSTALLER}

do-build:
	cd ${WRKSRC}; \
	${MV} -f mimeinstall.sh mimeinstall.sh.old; \
	${SED}	-e 's#@@PREFIX@@#'${PREFIX}'#g' \
		-e 's#@@REALPLAYER_HOME@@#'${REALPLAYER_HOME}'#g' \
		< mimeinstall.sh.old > mimeinstall.sh; \
		${CHMOD} +x mimeinstall.sh
	${SED}	-e 's#@@REALPLAYER_HOME@@#${REALPLAYER_HOME}#g' \
		< ${FILESDIR}/realplay.sh > ${WRKDIR}/realplay.sh

pre-install:
	${FIND} ${WRKSRC} \
		\( -name "*.orig" -o -name "*.old" \) -exec ${RM} {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplay.sh ${PREFIX}/bin/realplay
	cd ${WRKDIR}; ${PAX} -rw RealPlayer7 ${PREFIX}/lib

post-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/raclass.zip ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${REALPLAYER_HOME}/rpnp.so ${NS_PLUGINS_DIR}
	${LN} -sf ../lib/RealPlayer7/rpnphelper ${PREFIX}/bin/rpnphelper
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
