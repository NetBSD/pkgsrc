# $NetBSD: Makefile,v 1.2 2004/11/17 11:35:16 xtraeme Exp $
#

DISTNAME=		skype_staticQT-${DIST_VERSION}
PKGNAME=		skype-${DIST_VERSION}
PKGREVISION=		1
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

DIST_VERSION=		0.92.0.12

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
