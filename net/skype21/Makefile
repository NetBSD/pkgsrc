# $NetBSD: Makefile,v 1.4 2013/02/04 09:42:48 wiz Exp $

DISTNAME=		skype-2.1.0.81
CATEGORIES=		net
MASTER_SITES=		http://download.skype.com/linux/
EXTRACT_SUFX=		.tar.bz2
# see https://developer.skype.com/LinuxSkype/ReleaseNotes for changes

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.skype.com/
COMMENT=		P2P VoIP software (2.1.x branch)
LICENSE=		skype21-license

RESTRICTED=		Complex terms for redistribution.
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_REQD=		suse>=11.3
EMUL_MODULES.linux=	base x11 alsa qt4 glx gtk2

USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}/${DISTNAME}

DATADIR=		${PREFIX}/share/skype
DOCDIR=			${PREFIX}/share/doc/skype

INSTALLATION_DIRS+=	bin share/applications share/skype share/doc/skype
INSTALLATION_DIRS+=	share/icons/hicolor/16x16/apps
INSTALLATION_DIRS+=	share/icons/hicolor/32x32/apps
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps

do-build:
	set -e; \
	{ ${ECHO} "#!${SH}"; \
	  ${ECHO} 'exec ${DATADIR}/skype --resources=${DATADIR} "$$@"'; \
	} > ${WRKSRC}/skype.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/skype.sh ${DESTDIR}${PREFIX}/bin/skype
	${INSTALL_DATA} ${WRKSRC}/skype.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_16x16.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/16x16/apps/skype.png
	${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_32x32.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/32x32/apps/skype.png
	${INSTALL_DATA} ${WRKSRC}/icons/SkypeBlue_48x48.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/skype.png
	${INSTALL_SCRIPT} ${WRKSRC}/skype ${DESTDIR}${DATADIR}
	cd ${WRKSRC} && pax -rwppm icons sounds ${DESTDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
