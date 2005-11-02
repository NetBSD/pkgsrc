# $NetBSD: Makefile,v 1.9.2.1 2005/11/02 22:33:02 salo Exp $
#

DISTNAME=		skype_staticQT-1.2.0.18
PKGNAME=		${DISTNAME:S/_staticQT//}
CATEGORIES=		net
MASTER_SITES=		http://download.skype.com/linux/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.skype.com/
COMMENT=		P2P VoIP software

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_base>=9.1:../../emulators/suse91_base
DEPENDS+=	suse_glx>=9.1:../../emulators/suse91_glx
DEPENDS+=	suse_fontconfig>=9.1:../../emulators/suse91_fontconfig
DEPENDS+=	suse_freetype2>=9.1:../../emulators/suse91_freetype2
DEPENDS+=	suse_x11>=9.1:../../emulators/suse91_x11
.include "../../emulators/suse_linux/Makefile.application"
.else
.include "../../mk/x11.buildlink3.mk"
.endif

ONLY_FOR_PLATFORM=	*-*-i386

NO_CONFIGURE=		yes
CHECK_SHLIBS=		no
USE_DIRS+=		xdg-1.1
WRKSRC=			${WRKDIR}/${PKGNAME}

RESTRICTED=             "Redistribution not allowed yet."
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
LICENSE=                skype-license

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
