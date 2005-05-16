# $NetBSD: Makefile,v 1.4 2005/05/16 01:15:31 jlam Exp $
#

DISTNAME=       et-linux-2.56-2.x86
PKGNAME=        et-2.56
CATEGORIES=     games
MASTER_SITES=   ftp://ftp.idsoftware.com/idstuff/et/linux/
EXTRACT_SUFX=   .run

MAINTAINER=     dhowland@users.sourceforge.net
HOMEPAGE=       http://games.activision.com/games/wolfenstein/
COMMENT=        Wolfenstein: Enemy Territory for Linux

NO_BUILD=	yes
USE_PKGINSTALL=	yes
ONLY_FOR_PLATFORM=	FreeBSD-*-i386 Linux-*-i386

PKGSRC_USE_TOOLS+=	gtar
ETDIR=		${PREFIX}/lib/lokigames/et
EXTRACT_CMD=	${TAIL} +356 ${DOWNLOADED_DISTFILE} | ${GTAR} xzf - \
		-C ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
DEPENDS+=       suse_base>=6.3:../../emulators/${SUSE_DIR_PREFIX}_base
.include "../../emulators/suse_linux/Makefile.application"
.endif

pre-extract:
	${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_DATA_DIR} ${ETDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/ET.xpm ${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/openurl.sh ${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/v1.02_Readme.htm ${ETDIR}/
	${INSTALL_DATA_DIR} ${ETDIR}/Docs
	cd ${WRKSRC}/Docs && ${PAX} -rw -p am . ${ETDIR}/Docs
	${INSTALL_DATA_DIR} ${ETDIR}/etmain
	cd ${WRKSRC}/etmain && ${PAX} -rw -p am . ${ETDIR}/etmain
	${INSTALL_DATA_DIR} ${ETDIR}/pb
	cd ${WRKSRC}/pb && ${PAX} -rw -p am . ${ETDIR}/pb
	${INSTALL_SCRIPT} ${WRKSRC}/bin/Linux/x86/et.x86 ${ETDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/Linux/x86/etded.x86 ${ETDIR}/
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/et.sh >${WRKDIR}/et
	${INSTALL_SCRIPT} ${WRKDIR}/et ${PREFIX}/bin
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/etded.sh >${WRKDIR}/etded
	${INSTALL_SCRIPT} ${WRKDIR}/etded ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
