# $NetBSD: Makefile,v 1.21 2009/09/11 10:09:13 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGREVISION=		1

PKGNAME=		poppler-qt-${POPPLER_VERS}

COMMENT=		PDF rendering library (QT wrapper)
MAINTAINER=		reed@reedmedia.net

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-cairo-output
CONFIGURE_ARGS+=	--disable-splash-output
CONFIGURE_ARGS+=	--enable-poppler-qt
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils
CONFIGURE_ARGS+=	--disable-cms

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt.pc.in

BUILD_DIRS=		qt
INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt.pc \
		${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
