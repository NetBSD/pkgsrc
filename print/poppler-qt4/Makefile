# $NetBSD: Makefile,v 1.28 2012/07/04 20:26:58 drochner Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt4-${POPPLER_VERS}

COMMENT=		PDF rendering library (QT4 wrapper)
MAINTAINER=		reed@reedmedia.net

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-cairo-output
CONFIGURE_ARGS+=	--enable-poppler-qt4
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils
CONFIGURE_ENV+=		MOCQT4=${QTDIR}/bin/moc

BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.poppler:Mpoppler-cms)
CONFIGURE_ARGS+=	--enable-cms
.else
CONFIGURE_ARGS+=	--disable-cms
.endif

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt4.pc.in

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=		qt4/src

pre-build:
	cd ${WRKSRC}/poppler && ${BUILD_MAKE_CMD} libpoppler-arthur.la

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt4.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_DEPMETHOD.qt4-tools?=	full

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
