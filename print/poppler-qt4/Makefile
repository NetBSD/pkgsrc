# $NetBSD: Makefile,v 1.1.1.1 2007/12/12 01:29:22 markd Exp $
#

.include "../../print/poppler/Makefile.common"

PKGNAME=		poppler-qt4-${POPPLER_VERS}

COMMENT=		PDF rendering library (QT4 wrapper)

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-cairo-output
CONFIGURE_ARGS+=	--disable-splash-output
CONFIGURE_ARGS+=	--enable-poppler-qt4
CONFIGURE_ARGS+=	--disable-gtk-test
CONFIGURE_ARGS+=	--disable-utils

PKGCONFIG_OVERRIDE+=	${WRKSRC}/poppler-qt4.pc.in

INSTALLATION_DIRS+=	lib include/poppler lib/pkgconfig

BUILD_DIRS=		${WRKSRC}/qt4/src

post-install:
	${INSTALL_DATA} ${WRKSRC}/poppler-qt4.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

BUILDLINK_API_DEPENDS.poppler+=     poppler>=${POPPLER_VERS}
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
