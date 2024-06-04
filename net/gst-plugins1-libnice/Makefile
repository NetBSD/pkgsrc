# $NetBSD: Makefile,v 1.57 2024/06/04 15:09:51 adam Exp $

PKGNAME=	gst-plugins1-${DISTNAME}
COMMENT+=	(gstreamer plugin)

INSTALL_DIRS=	# disable meson install

.include "../../net/libnice/Makefile.common"

MESON_ARGS+=	-Dgstreamer=enabled
MESON_ARGS+=	-Dexamples=disabled
MESON_ARGS+=	-Dintrospection=disabled
MESON_ARGS+=	-Dtests=disabled

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

INSTALLATION_DIRS+=	lib/gstreamer-1.0

do-install:
	${INSTALL_LIB} ${WRKSRC}/output/gst/libgstnice.${SOEXT} \
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
