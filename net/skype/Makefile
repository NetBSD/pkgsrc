# $NetBSD: Makefile,v 1.28 2008/08/24 10:08:39 wiz Exp $
#

DISTNAME=		skype_static-1.4.0.118-oss
PKGNAME=		skype-1.4.0.118
CATEGORIES=		net
MASTER_SITES=		http://download.skype.com/linux/
EXTRACT_SUFX=		.tar.bz2
# see https://developer.skype.com/LinuxSkype/ReleaseNotes for changes

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.skype.com/
COMMENT=		P2P VoIP software

LICENSE=		skype-license
RESTRICTED=		Complex terms for redistribution.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat fontconfig freetype2 glx \
			libsigc++2 resmgr x11

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}/${DISTNAME}

DATADIR=		${PREFIX}/share/skype
DOCDIR=			${PREFIX}/share/doc/skype

INSTALLATION_DIRS=	bin

do-build:
	set -e; \
	{ ${ECHO} "#!${SH}"; \
	  ${ECHO} 'exec ${DATADIR}/skype --resources=${DATADIR} "$$@"'; \
	} > ${WRKSRC}/skype.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/skype.sh ${PREFIX}/bin/skype
	${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/skype ${DATADIR}
	cd ${WRKSRC} && pax -rwppm icons sounds ${DATADIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
