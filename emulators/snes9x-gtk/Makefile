# $NetBSD: Makefile,v 1.68 2019/07/21 22:24:47 wiz Exp $

PKGREVISION= 2
.include "../../emulators/snes9x/Makefile.common"

PKGNAME=	snes9x-gtk-${SNES9X_VERSION}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Super Nintendo Entertainment System (SNES) emulator (GUI version)

USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt xgettext msgmerge
USE_TOOLS+=	gawk

MESON_ARGS+=	-Dsystem-zip=false
MESON_ARGS+=	-Dportaudio=false

BUILD_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
BUILD_DEPENDS+=	${PYPKGPREFIX}-meson-[0-9]*:../../devel/py-meson

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	gtk/src/gtk_sound_driver_oss.cpp
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

LDFLAGS.SunOS+=		-lsocket -lnsl

do-configure:
	cd ${WRKSRC}/gtk && ${SETENV} ${MAKE_ENV} meson --prefix ${PREFIX} --libdir lib --mandir ${PKGMANDIR} --buildtype=plain ${MESON_ARGS} . output

do-build:
	cd ${WRKSRC}/gtk && ${SETENV} ${MAKE_ENV} ninja -C output

do-install:
	cd ${WRKSRC}/gtk && ${SETENV} ${INSTALL_ENV} ninja -C output install

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
