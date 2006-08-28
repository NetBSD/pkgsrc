# $NetBSD: Makefile,v 1.18 2006/08/28 07:54:05 ghen Exp $
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

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=	suse_base-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_base
DEPENDS+=	suse_glx-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_glx
DEPENDS+=	suse_fontconfig-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_fontconfig
DEPENDS+=	suse_freetype2-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_freetype2
DEPENDS+=	suse_x11-[0-9]*:../../emulators/${SUSE_DIR_PREFIX}_x11
.else
.include "../../mk/x11.buildlink3.mk"
.endif

ONLY_FOR_PLATFORM=	*-*-i386

NO_CONFIGURE=		yes
USE_DIRS+=		xdg-1.1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

RESTRICTED=		Redistribution not allowed yet.
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}
LICENSE=		skype-license

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
