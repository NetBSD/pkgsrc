# $NetBSD: Makefile,v 1.11 2020/11/24 13:04:52 nia Exp $

DISTNAME=	quake2-7.45
PKGNAME=	y${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	https://deponie.yamagi.org/quake2/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yamagi.org/quake2/
COMMENT=	Yamagi Quake II - alternative Quake II client
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
USE_LANGUAGES=	c99

MAKE_FLAGS+=	WITH_SYSTEMWIDE=yes
MAKE_FLAGS+=	WITH_SYSTEMDIR=${PREFIX}/share/yquake2

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec/yquake2
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	share/yquake2/baseq2

pre-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},g' < ${FILESDIR}/quake2.sh.in > ${WRKDIR}/quake2.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/quake2.sh \
	    ${DESTDIR}${PREFIX}/bin/quake2
	${INSTALL_SCRIPT} ${WRKDIR}/quake2.sh \
	    ${DESTDIR}${PREFIX}/bin/q2ded
	${INSTALL_PROGRAM} ${WRKSRC}/release/quake2 \
	    ${DESTDIR}${PREFIX}/libexec/yquake2/quake2
	${INSTALL_PROGRAM} ${WRKSRC}/release/q2ded \
	    ${DESTDIR}${PREFIX}/libexec/yquake2/q2ded
	${INSTALL_LIB} ${WRKSRC}/release/baseq2/game.so \
	    ${DESTDIR}${PREFIX}/share/yquake2/baseq2
	${INSTALL_LIB} ${WRKSRC}/release/*.so \
	    ${DESTDIR}${PREFIX}/libexec/yquake2
	${INSTALL_DATA} ${FILESDIR}/yquake2.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/stuff/icon/Quake2.png \
	    ${DESTDIR}${PREFIX}/share/pixmaps/quake2.png

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
