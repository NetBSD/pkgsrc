# $NetBSD: Makefile,v 1.5 2023/01/29 21:16:19 ryoon Exp $
#

DISTNAME=	openhexagon-2.0
PKGREVISION=	4
CATEGORIES=	games

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vittorioromeo.info/projects.html
COMMENT=	Open-source clone of the game "Super Hexagon by Terry Cavanagh"
LICENSE=	afl-3.0

USE_LANGUAGES=	c c++14
USE_CMAKE=	yes
USE_TOOLS+=	pax sed

# (sorted in dependency order)
MODULES=	SSVUtils-c8190f843ab5bdfcff99e92aec7421c413c887e3 \
		SSVEntitySystem-8123beabe3bc8ffe91cb94e6ba061254f3bba18b \
		SSVJsonCpp-a45c64c418dc0b1fab1eec52fa70b6a14308c635 \
		SSVUtilsJson-95836250e3a9b65883f22991190e652a455121c1 \
		SSVStart-112229f184f5e4cf88c71fe67b4588806d290f71 \
		SSVMenuSystem-03d32b26b2880a35d5daa1ad7ab6199a4d19c742 \
		SSVLuaWrapper-ca905bddae86358182cf85eff2d0220ccdd785d0 \
		SSVOpenHexagonAssets-1d125de695be2e74c9f2ad3198e8b5b29911d010 \
		SSVOpenHexagon-2.0-preview

.for dist in ${MODULES:=.tar.gz}
DISTFILES+=	${dist}
SITES.${dist}+=	${MASTER_SITE_GITHUB:S,^,-,:=SuperV1234/${dist:S,-,/archive/,}}
.endfor

WRKSRC=		${WRKDIR}/${MODULES:MSSVOpenHexagon-*}

SUBST_CLASSES+=		wrap
SUBST_STAGE.wrap=	pre-configure
SUBST_MESSAGE.wrap=	Adjusting shell wrapper
SUBST_FILES.wrap=	${PKGBASE}
SUBST_VARS.wrap=	PREFIX PKGBASE

SUBST_CLASSES+=		include
SUBST_STAGE.include=	post-configure
SUBST_MESSAGE.include=	Fixing hardcoded include path
SUBST_FILES.include=	extlibs/SSVLuaWrapper/include/SSVLuaWrapper/LuaContext/LuaContext.h
SUBST_SED.include=	-e 's,lua5.1,lua-${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR},'

CMAKE_ARGS+=	-DPKGBASE=${PKGBASE}
CMAKE_ARGS+=	-DBUILD_SHARED_LIB:BOOL=OFF
CMAKE_ARGS+=	-DLUA_LIBRARY=${BUILDLINK_DIR}/lib/liblua${LUA_VERSION_MAJOR}.${LUA_VERSION_MINOR}.so
CMAKE_ARGS+=	-DLUA_INCLUDE_DIR=${BUILDLINK_DIR}/${LUA_INCDIR}

.for mod in ${MODULES:NSSVOpenHexagon*:C/-.*//}
CMAKE_ARGS+=	-D${mod:tu}_INCLUDE_DIR=${WRKSRC}/extlibs/${mod}/include
CMAKE_ARGS+=	-D${mod:tu}_LIBRARY_RELEASE=${WRKSRC}/extlibs/${mod}/lib${mod}-s.a
.endfor

CONFIGURE_DIRS+=	${MODULES:NSSVOpenHexagon*:C/-.*//:%=extlibs/%} .

INSTALL_DIRS+=		.

INSTALLATION_DIRS+=	bin lib/${PKGBASE}

pre-patch:
	for d in ${WRKDIR}/*/extlibs/*; do \
		${RMDIR} $${d} && ${LN} -s ${WRKDIR}/$${d##*/}-* $${d}; \
	done

post-extract:
	${CP} ${FILESDIR}/${PKGBASE}.sh ${WRKSRC}/${PKGBASE}

post-build:
	for p in ${WRKDIR}/${MODULES:MSSVOpenHexagonAssets-*}/_RELEASE/Packs/*; do \
	    ${ECHO} "{ \"name\":\"$${p##*/}\", \"priority\":0 }" >$${p}/pack.json; \
	done

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin
	cd ${WRKDIR}/${MODULES:MSSVOpenHexagonAssets-*}/_RELEASE && \
	    ${PAX} -rwpm Assets Packs ${DESTDIR}${PREFIX}/lib/${PKGBASE}

LUA_VERSIONS_ACCEPTED=	51

.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/sfml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
