# $NetBSD: Makefile,v 1.36 2013/03/24 07:09:26 spz Exp $
#

.include "../../print/poppler016/Makefile.common"

PKGNAME=		poppler-qt-${POPPLER_VERS}

COMMENT=		PDF rendering library (QT wrapper)
MAINTAINER=		reed@reedmedia.net

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-cairo-output
CONFIGURE_ARGS+=	--disable-splash-output
CONFIGURE_ARGS+=	--enable-poppler-qt
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler016/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
CONFIGURE_ARGS+=	--enable-cms
.else
CONFIGURE_ARGS+=	--disable-cms
.endif

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt.pc.in

BUILD_DIRS=		qt
INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
