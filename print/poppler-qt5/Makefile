# $NetBSD: Makefile,v 1.7 2016/03/05 11:29:17 jperkin Exp $

PKGREVISION= 1
.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt5-${POPPLER_VERS}
COMMENT=		PDF rendering library (QT5 wrapper)
MAINTAINER=		pkgsrc-users@NetBSD.org

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-cairo-output
CONFIGURE_ARGS+=	--enable-poppler-qt5
CONFIGURE_ARGS+=	--disable-poppler-qt4
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils
CONFIGURE_ENV+=		MOCQT5=${QTDIR}/bin/moc

USE_TOOLS+=		gmake

BUILDLINK_API_DEPENDS.poppler+= poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt5.pc.in

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=		qt5/src

pre-build:
	cd ${WRKSRC}/qt5/src && ${BUILD_MAKE_CMD}

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt5.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
