# $NetBSD: Makefile,v 1.4 2005/02/18 12:48:10 martti Exp $
#

DISTNAME=		skype_staticQT-${DIST_VERSION}
PKGNAME=		skype-${DIST_VERSION}
CATEGORIES=		net
MASTER_SITES=		http://download.skype.com/linux/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.skype.com/
COMMENT=		P2P VoIP software

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=	suse_base>=9.1:../../emulators/suse91_base
DEPENDS+=	suse_fontconfig>=9.1:../../emulators/suse91_fontconfig
DEPENDS+=	suse_freetype2>=9.1:../../emulators/suse91_freetype2
DEPENDS+=	suse_x11>=9.1:../../emulators/suse91_x11
.include "../../emulators/suse_linux/Makefile.application"
.else
USE_X11=	yes
.endif

ONLY_FOR_PLATFORM=	*-*-i386

NO_BUILD=		yes
NO_CONFIGURE=		yes
CHECK_SHLIBS=		no

DIST_VERSION=		1.0.0.1

RESTRICTED=             "Redistribution not allowed yet."
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}
LICENSE=                skype-license

DATADIR=		${PREFIX}/share/skype

do-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKSRC} && ${PAX} -rwppm . ${DATADIR}
	@${ECHO} "#!${SH}" > ${WRKSRC}/skype.sh
	@${ECHO} 'cd ${DATADIR} && exec ./skype $$@' >> ${WRKSRC}/skype.sh
	${INSTALL_SCRIPT} ${WRKSRC}/skype.sh ${PREFIX}/bin/skype

.include "../../mk/bsd.pkg.mk"
