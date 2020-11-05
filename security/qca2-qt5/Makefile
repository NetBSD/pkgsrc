# $NetBSD: Makefile,v 1.15 2020/11/05 09:07:07 ryoon Exp $

PKGNAME=	qca2-qt5-${DISTNAME:C/.*-//}
PKGREVISION=	7

COMMENT=	Cross-platform crypto API for QT5

.include "../../security/qca2/Makefile.common"

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

INSTALLATION_DIRS=	lib/pkgconfig

CMAKE_ARGS+=	-DBUILD_PLUGINS=none
CMAKE_ARGS+=	-DQCA_MAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE=		lib/pkgconfig/qca2-qt5.pc 
PKGCONFIG_OVERRIDE_STAGE=	post-configure

post-install:
	${INSTALL_DATA} ${DESTDIR}${QTDIR}/lib/pkgconfig/qca2-qt5.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/qca2-qt5.pc

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
