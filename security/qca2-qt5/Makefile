# $NetBSD: Makefile,v 1.33 2024/11/01 12:54:19 wiz Exp $

PKGNAME=	qca2-qt5-${DISTNAME:C/.*-//}
PKGREVISION=	3

COMMENT=	Cross-platform crypto API for Qt5

.include "../../security/qca2-qt5/Makefile.common"

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

INSTALLATION_DIRS=	lib/pkgconfig

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PLUGINS=none
CMAKE_CONFIGURE_ARGS+=	-DQCA_MAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE=		lib/pkgconfig/qca2-qt5.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

post-install:
	${INSTALL_DATA} ${DESTDIR}${QTDIR}/lib/pkgconfig/qca2-qt5.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/qca2-qt5.pc

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
