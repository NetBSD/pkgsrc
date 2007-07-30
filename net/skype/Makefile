# $NetBSD: Makefile,v 1.20 2007/07/30 19:20:29 wiz Exp $
#

DISTNAME=		skype_staticQT-1.2.0.18
PKGNAME=		${DISTNAME:S/_staticQT//}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://download.skype.com/linux/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.skype.com/
COMMENT=		P2P VoIP software

RESTRICTED=		Redistribution not allowed yet.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=		skype-license

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base compat fontconfig freetype2 glx x11

USE_DIRS+=		xdg-1.1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

DATADIR=		${PREFIX}/share/skype
DOCDIR=			${PREFIX}/share/doc/skype

INSTALLATION_DIRS=	bin

do-build:
	@${ECHO} "#!${SH}" > ${WRKSRC}/skype.sh
	@${ECHO} 'cd ${DATADIR} && exec ./skype $$@' >> ${WRKSRC}/skype.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/skype.sh ${PREFIX}/bin/skype
	${INSTALL_DATA} ${WRKSRC}/skype.desktop ${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/skype ${DATADIR}
	cd ${WRKSRC} && ${PAX} -rwppm icons lang sound ${DATADIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
