# $NetBSD: Makefile,v 1.17 2013/04/06 12:04:00 rodent Exp $
#

DISTNAME=	et-linux-2.56-2.x86
PKGNAME=	et-2.56
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/et/linux/
EXTRACT_SUFX=	.run

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://games.activision.com/games/wolfenstein/
COMMENT=	Wolfenstein: Enemy Territory for Linux

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base glx

USE_TOOLS+=	gtar pax
EXTRACT_CMD=	${TAIL} +356 $$extract_file | ${GTAR} xzf - \
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
	${INSTALL_DATA_DIR} ${DESTDIR}${ETDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${DESTDIR}${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/ET.xpm ${DESTDIR}${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/openurl.sh ${DESTDIR}${ETDIR}/
	${INSTALL_DATA} ${WRKSRC}/v1.02_Readme.htm ${DESTDIR}${ETDIR}/
	${INSTALL_DATA_DIR} ${DESTDIR}${ETDIR}/Docs
	cd ${WRKSRC}/Docs && pax -rw -p am . ${DESTDIR}${ETDIR}/Docs
	${INSTALL_DATA_DIR} ${DESTDIR}${ETDIR}/etmain
	cd ${WRKSRC}/etmain && pax -rw -p am . ${DESTDIR}${ETDIR}/etmain
	${INSTALL_DATA_DIR} ${DESTDIR}${ETDIR}/pb
	cd ${WRKSRC}/pb && pax -rw -p am . ${DESTDIR}${ETDIR}/pb
	${INSTALL_SCRIPT} ${WRKSRC}/bin/Linux/x86/et.x86 ${DESTDIR}${ETDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/bin/Linux/x86/etded.x86 ${DESTDIR}${ETDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/et ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/etded ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
