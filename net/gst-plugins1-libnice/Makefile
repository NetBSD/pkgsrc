# $NetBSD: Makefile,v 1.65 2025/05/06 12:07:35 wiz Exp $

PKGNAME=	gst-plugins1-${DISTNAME}
PKGREVISION=	2
COMMENT+=	(gstreamer plugin)

INSTALL_DIRS=	# disable meson install

.include "../../net/libnice/Makefile.common"

MESON_ARGS+=	-Dgstreamer=enabled
MESON_ARGS+=	-Dexamples=disabled
MESON_ARGS+=	-Dintrospection=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS+=	lib/gstreamer-1.0

do-install:
	${INSTALL_LIB} ${WRKSRC}/output/gst/libgstnice.${SHLIB_EXT} \
		${DESTDIR}${PREFIX}/lib/gstreamer-1.0
.if ${OPSYS} == "Darwin"
	cd ${DESTDIR}${PREFIX}/lib/gstreamer-1.0 && \
	install_name_tool -change @rpath/libnice.10.dylib ${PREFIX}/lib/libnice.10.dylib \
		-id ${PREFIX}/lib/gstreamer-1.0/libgstnice.dylib libgstnice.dylib
.endif

.include "../../net/libnice/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
