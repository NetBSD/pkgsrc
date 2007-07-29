# $NetBSD: Makefile,v 1.12 2007/07/29 05:19:25 jlam Exp $
#

DISTNAME=	et-linux-2.56-2.x86
PKGNAME=	et-2.56
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/et/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://games.activision.com/games/wolfenstein/
COMMENT=	Wolfenstein: Enemy Territory for Linux

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

USE_TOOLS+=	gtar
EXTRACT_CMD=	${TAIL} +356 ${DOWNLOADED_DISTFILE} | ${GTAR} xzf - \
		-C ${WRKSRC}

ETDIR=		${PREFIX}/lib/lokigames/et
BUILD_DIRS=	# empty

INSTALLATION_DIRS=	bin

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/et ${WRKDIR}/etded
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@SH@,${SH},g'
SUBST_STAGE.paths=	post-patch

pre-extract:
	${MKDIR} ${WRKSRC}

post-extract:
	${CP} ${FILESDIR}/et.sh ${WRKDIR}/et
	${CP} ${FILESDIR}/etded.sh ${WRKDIR}/etded

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
	${INSTALL_SCRIPT} ${WRKDIR}/et ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/etded ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
