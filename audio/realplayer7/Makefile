# $NetBSD: Makefile,v 1.1.1.1 2000/03/22 08:42:29 rh Exp $
#

DISTNAME=		rp7install
PKGNAME=		realplayer-7nb1
WRKSRC=			${WRKDIR}/RealPlayer7
CATEGORIES=		audio
MASTER_SITES=
EXTRACT_SUFX=		.bin

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.real.com/products/player/

DEPENDS+=		suse_linux>=6.1:../../emulators/suse_linux

ONLY_FOR_PLATFORM=	NetBSD-*-i386
NO_CDROM=		"Redistribution not permitted"
RESTRICTED=		"Export-controlled"
MIRROR_DISTFILE=	no
IS_INTERACTIVE=		yes

NO_CONFIGURE=		yes
EXTRACT_CMD=		HOME=${WRKDIR} ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

DOWNLOAD=		http://proforma.real.com/real/player/linuxplayer.html
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer7

NS_PLUGINS_DIR=	${PREFIX}/lib/netscape/plugins

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  RealPlayer 7 for Linux 2.0/2.2 must be fetched into"; \
	    ${ECHO_MSG} "  ${DISTDIR} from"; \
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
	@${ECHO_MSG} " Then cancel out of the plugin install, and register   "
	@${ECHO_MSG} " if you choose to, otherwise cancel.                   "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " After the introductory clip runs, exit RealPlayer     "
	@${ECHO_MSG} " to continue the package installation.                 "
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} ""
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

post-patch:
	cd ${WRKSRC}; \
	${MV} -f mimeinstall.sh mimeinstall.sh.old; \
	${SED} -e 's#@@PREFIX@@#'${PREFIX}'#g' \
		< mimeinstall.sh.old >mimeinstall.sh; \
		${CHMOD} +x mimeinstall.sh; \
	${RM} mimeinstall.sh.orig mimeinstall.sh.old

do-build:
	${SED} -e 's#@@REALPLAYER_HOME@@#${REALPLAYER_HOME}#g' \
	    <${FILESDIR}/realplay.sh >${WRKDIR}/realplay.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplay.sh ${PREFIX}/bin/realplay
	cd ${WRKDIR}; ${PAX} -rw RealPlayer7 ${PREFIX}/lib

post-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${PREFIX}/lib/RealPlayer7/raclass.zip ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${PREFIX}/lib/RealPlayer7/rpnp.so ${NS_PLUGINS_DIR}
	${LN} -sf ../lib/RealPlayer7/rpnphelper ${PREFIX}/bin/rpnphelper
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
