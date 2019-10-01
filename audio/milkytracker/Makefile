# $NetBSD: Makefile,v 1.13 2019/10/01 19:37:50 nia Exp $

DISTNAME=	milkytracker-1.02.00
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=milkytracker/}
GITHUB_PROJECT=	MilkyTracker
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://milkytracker.titandemo.org/
COMMENT=	Music tracker inspired by Fast Tracker 2
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++03

INSTALLATION_DIRS+=	share/appdata
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${WRKSRC}/resources/pictures/carton.png \
		${DESTDIR}${PREFIX}/share/pixmaps/milkytracker.png
	${INSTALL_DATA} ${WRKSRC}/resources/milkytracker.appdata \
		${DESTDIR}${PREFIX}/share/appdata/milkytracker.appdata.xml
	${INSTALL_DATA} ${WRKSRC}/resources/milkytracker.desktop \
		${DESTDIR}${PREFIX}/share/applications

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../archivers/lhasa/buildlink3.mk"
.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.endif
.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.endif
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
