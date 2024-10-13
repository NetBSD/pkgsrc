# $NetBSD: Makefile,v 1.31 2024/10/13 20:56:41 yhardy Exp $
DISTNAME=		REminiscence-0.5.2
CATEGORIES=		games
MASTER_SITES=		http://cyxdown.free.fr/reminiscence/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.tar.bz2
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		opl3.h opl3.c
DISTFILES+=		stb_vorbis.c
SITES.opl3.h=		${MASTER_SITE_GITHUB:=nukeykt/}Nuked-OPL3/raw/cfedb09efc03f1d7b5fc1f04dd449d77d8c49d50/
SITES.opl3.c=		${MASTER_SITE_GITHUB:=nukeykt/}Nuked-OPL3/raw/cfedb09efc03f1d7b5fc1f04dd449d77d8c49d50/
SITES.stb_vorbis.c=	${MASTER_SITE_GITHUB:=nothings/}stb/raw/1ee679ca2ef753a528db5ba6801e1067b40481b8/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cyxdown.free.fr/reminiscence/
COMMENT=		Engine to play Flashback by Delphine Software
LICENSE=		gnu-gpl-v3 AND gnu-lgpl-v2.1 AND public-domain

USE_LANGUAGES=		c++

BUILD_TARGET=		rs

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/doc/REminiscence

pre-build:
	${CP} ${WRKDIR}/opl3.h ${WRKSRC}/
	${CP} ${WRKDIR}/opl3.c ${WRKSRC}/
	${CP} ${WRKDIR}/stb_vorbis.c ${WRKSRC}/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rs ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/reminiscence.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/README.txt \
		${DESTDIR}${PREFIX}/share/doc/REminiscence

.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/tremor/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
