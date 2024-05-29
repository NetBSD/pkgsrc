# $NetBSD: Makefile,v 1.46 2024/05/29 16:32:27 adam Exp $

DISTNAME=	raine-0.96.7
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=zelurker/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://raine.1emulation.com/
COMMENT=	680x0 Arcade Emulator

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	gmake perl:run pkg-config xgettext
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile
REPLACE_PERL=	makedep
PTHREAD_OPTS+=	require

MAKE_FLAGS+=	OSTYPE=linux-gnu
MAKE_FLAGS+=	NO_ASM=1
MAKE_FLAGS+=	INSTALL_BIN=${INSTALL_PROGRAM:Q}
MAKE_FLAGS+=	INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=	prefix=${DESTDIR}/${PREFIX}
MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
MAKE_FLAGS+=	sharedir=${DESTDIR}${PREFIX}/share
MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
MAKE_FLAGS+=	rainedata=${DESTDIR}${PREFIX}/share/raine

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	source/raine.c
SUBST_SED.paths+=	-e "s,/usr/share/games/raine,${PREFIX}/share/raine,g"

USE_CXX_FEATURES+=	unique_ptr

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

LUA_VERSIONS_ACCEPTED=	54 53

post-build:
	(${ECHO} "#!${SH}";					\
	 ${ECHO} "cd ${PREFIX}/share/raine && ./raine $$@")	\
		> ${WRKSRC}/raine.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/raine ${DESTDIR}${PREFIX}/share/raine
	${INSTALL_SCRIPT} ${WRKSRC}/raine.sh ${DESTDIR}${PREFIX}/bin/raine

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
