# $NetBSD: Makefile,v 1.1.1.1 2000/02/17 22:44:19 jlam Exp $
#

DISTNAME=		g2a1_linux22
PKGNAME=		realplayerG2-1a
CATEGORIES=		audio
MASTER_SITES=
EXTRACT_SUFX=		.bin

MAINTAINER=		jlam@netbsd.org
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
REALPLAYER_HOME=	${PREFIX}/lib/RealPlayerG2

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	    ${ECHO_MSG} "==============================================================="; \
	    ${ECHO_MSG} "  RealPlayer G2 for Linux 2.0/2.2 must be fetched into"; \
	    ${ECHO_MSG} "  ${DISTDIR} from"; \
	    ${ECHO_MSG} "  ${DOWNLOAD}."; \
	    ${ECHO_MSG} "==============================================================="; \
	    ${FALSE}; \
	fi

pre-extract:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} " Now running the RealPlayerG2 installation script.     "
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Simply hit <RETURN> on every request.  Please do      "
	@${ECHO_MSG} " _not_ try to change any setup parameters.             "
	@${ECHO_MSG} "-------------------------------------------------------"
	@${ECHO_MSG} ""
	@${CHMOD} +x ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}

do-build:
	${SED} -e 's#@@REALPLAYER_HOME@@#${REALPLAYER_HOME}#g' \
	    <${FILESDIR}/realplay.sh >${WRKDIR}/realplay.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/realplay.sh ${PREFIX}/bin/realplay
	cd ${WRKDIR}; ${PAX} -rw RealPlayerG2 ${PREFIX}/lib

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
