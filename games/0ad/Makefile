# $NetBSD: Makefile,v 1.3 2023/05/04 17:29:33 nikita Exp $

.include "Makefile.common"

DISTNAME=	${DISTVERSION}-build
PKGNAME=	${DISTNAME:S/-unix-build//:S/-alpha/.alpha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Historical real-time strategy game
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix-build//}
# Requires C++17 and add "--std" option itself
GCC_REQD+=	7
USE_LANGUAGES=	c c++

USE_TOOLS+=	cmake bash gmake pax perl pkg-config

DEPENDS+=		0ad-data-${PKGVERSION_NOREV}{,nb*}:../../games/0ad-data
BUILD_DEPENDS+=		premake5-[0-9]*:../../devel/premake5
TOOL_DEPENDS+=		patchelf-[0-9]*:../../devel/patchelf

SUBST_CLASSES+=			sysincludedir
SUBST_MESSAGE.sysincludedir=	Fixing "/usr/local" path assumption
SUBST_STAGE.sysincludedir=	pre-configure
SUBST_FILES.sysincludedir=	build/premake/extern_libs5.lua
SUBST_FILES.sysincludedir+=	build/premake/premake5.lua
SUBST_SED.sysincludedir+=	-e "s,/usr/local/,${PREFIX}/,g"

# thanks to Guix:
# 0ad only builds fine with a specific version of mozjs
# (version 78.6 for 0ad-0.0.25).
# Here we change the error in case of version mismatch to a warning,
# and add some minor compatibility fixes.
SUBST_CLASSES+=		mozjs
SUBST_MESSAGE.mozjs=	Fixing mozjs version error
SUBST_STAGE.mozjs=	pre-configure
SUBST_FILES.mozjs=	source/scriptinterface/ScriptTypes.h
SUBST_SED.mozjs+=	-e "s,\#error Your compiler is trying to use,\#warning Your compiler is trying to use,g"

SUBST_CLASSES+=		mozjs2
SUBST_MESSAGE.mozjs2=	Fixing mozjs version error
SUBST_STAGE.mozjs2=	pre-configure
SUBST_FILES.mozjs2+=	source/scriptinterface/ScriptContext.cpp
SUBST_SED.mozjs2+=	-e "s|JS::PrepareZoneForGC(|JS::PrepareZoneForGC(m_cx, |g"

DATADIR=		${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib/${PKGBASE}
INSTALLATION_DIRS+=	${DATADIR}
INSTALLATION_DIRS+=	${DATADIR}/mods/public
INSTALLATION_DIRS+=	${DATADIR}/mods/mod
INSTALLATION_DIRS+=	${DATADIR}/config
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

.if ${MACHINE_ARCH} == "i386"
CFLAGS+=	-msse
.endif

.include "options.mk"

# nvtt, notes from gentoo:
# Build bundled NVTT
# nvtt is abandoned upstream and 0ad has forked it and added fixes.
# Use their copy. bug #768930
# --with-system-nvtt

do-configure:
	${RUN} cd ${WRKSRC}/build/workspaces && ./clean-workspaces.sh
	${RUN} cd ${WRKSRC}/build/workspaces && ./update-workspaces.sh \
		--bindir=${PREFIX}/bin \
		--datadir=${DATADIR} \
		--libdir=${PREFIX}/lib/${PKGBASE} \
		--with-system-premake5 \
		--with-system-mozjs \
		--without-pch \
		${CONFIGURE_EDITOR} ${CONFIGURE_TESTS}

do-build:
	${RUN} cd ${WRKSRC} && \
		${GMAKE} config=release verbose=1 -j ${_MAKE_JOBS_N:U1} \
		-C build/workspaces/gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${DESTDIR}${PREFIX}/bin/0ad
.if !empty(PKG_OPTIONS:Meditor)
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/ActorEditor ${DESTDIR}${PREFIX}/bin
	# why? you have the rpath. don't produce nonsense?
	${PREFIX}/bin/patchelf --force-rpath --set-rpath \
		${PREFIX}/lib/${PKGBASE}:${PREFIX}/lib \
		${DESTDIR}${PREFIX}/bin/ActorEditor
	${PREFIX}/bin/patchelf --replace-needed \
		"../../../binaries/system/libAtlasUI.so" libAtlasUI.so \
		${DESTDIR}${PREFIX}/bin/ActorEditor
	cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} \
		libAtlasUI.so libAtlasObject.a ${DESTDIR}${PREFIX}/lib/${PKGBASE}
.endif
	# TODO: all of these should be .so.
	cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libatlas.a \
		libengine.a libgladwrapper.a libglooxwrapper.a libgraphics.a \
		libgui.a liblobby.a liblowlevel.a libmocks_real.a libmocks_test.a \
		libmongoose.a libnetwork.a librlinterface.a libscriptinterface.a \
		libsimulation2.a libtinygettext.a libCollada.so \
		libnvcore.so libnvimage.so libnvmath.so libnvtt.so \
		${DESTDIR}${PREFIX}/lib/${PKGBASE}
	# hack. figure out where to set the rpath in the cmake build of the bundled nvtt.
.for f in libnvcore libnvimage libnvmath libnvtt
	${PREFIX}/bin/patchelf \
		--force-rpath \
		--set-rpath ${PREFIX}/lib/${PKGBASE}:${PREFIX}/lib \
		${DESTDIR}${PREFIX}/lib/${PKGBASE}/${f}.so
.endfor
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${DESTDIR}${PREFIX}/share/pixmaps
	cd ${WRKSRC}/binaries/data && ${PAX} -rw l10n ${DESTDIR}${DATADIR}
.if !empty(PKG_OPTIONS:Mtests)
	cd ${WRKSRC}/binaries/data && ${PAX} -rw tests ${DESTDIR}${DATADIR}
.endif

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../chat/gloox/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/mozjs78/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python/tool.mk"
.endif
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
