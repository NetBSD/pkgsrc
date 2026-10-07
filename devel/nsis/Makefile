# $NetBSD: Makefile,v 1.28 2026/10/07 14:06:58 sborrill Exp $

DISTNAME=	nsis-${NSIS_VER}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nsis/}
EXTRACT_SUFX=	.zip .tar.bz2
DISTFILES=	${DISTNAME}.zip \
		${NSIS_SRC}.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nsis.sourceforge.io/Main_Page
COMMENT=	Scriptable system to build Windows installers
LICENSE=	zlib

MAKE_JOBS_SAFE=	no # fails to build in parallel
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax

NSIS_SRC=	${DISTNAME:=-src}
NSIS_VER=	3.12
WRKSRC=		${WRKDIR}/${NSIS_SRC}
NO_CONFIGURE=	yes
USE_GNU_ICONV=	yes
EXTRACT_OPTS_ZIP=	-qo

MAKENSIS_BIN=	${PREFIX}/share/nsis/makensis

INSTALLATION_DIRS=	bin share/nsis

SUBST_CLASSES+=		makensis
SUBST_STAGE.makensis=	pre-build
SUBST_FILES.makensis=	makensis.sh
SUBST_SED.makensis=	-e s,@@SH@@,${SH:Q},
SUBST_SED.makensis+=	-e s,@@MAKENSIS@@,${MAKENSIS_BIN:Q},

# https://nsis.sourceforge.io/Docs/AppendixG.html#build_posix
SCONS_BUILD_ARGS+=	APPEND_CCFLAGS=${CFLAGS:Q}
SCONS_BUILD_ARGS+=	APPEND_LINKFLAGS=${LDFLAGS:Q}
SCONS_BUILD_ARGS+=	NSIS_CONFIG_CONST_DATA_PATH=yes
SCONS_BUILD_ARGS+=	SKIPMISC=all
SCONS_BUILD_ARGS+=	SKIPPLUGINS=all
SCONS_BUILD_ARGS+=	SKIPSTUBS=all
SCONS_BUILD_ARGS+=	SKIPUTILS=all
SCONS_BUILD_ARGS+=	VERSION=${NSIS_VER:Q}
SCONS_DO_INSTALL=	no

post-extract:
	${CP} ${FILESDIR}/makensis.sh ${WRKSRC}
	chmod -R go-w ${WRKDIR}/*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/urelease/makensis/makensis	\
		${DESTDIR}${MAKENSIS_BIN:Q}
	${INSTALL_SCRIPT} ${WRKSRC}/makensis.sh		\
		${DESTDIR}${PREFIX}/bin/makensis
	cd ${WRKDIR}/${DISTNAME} && ${PAX} -rw .	\
		${DESTDIR}${PREFIX}/share/nsis

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/scons4/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
