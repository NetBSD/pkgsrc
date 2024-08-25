# $NetBSD: Makefile,v 1.49 2024/08/25 06:19:13 wiz Exp $

PKGNAME=	qca2-${DISTNAME:C/.*-//}
PKGREVISION=	7

COMMENT=	Cross-platform crypto API for QT

.include "Makefile.common"

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

INSTALLATION_DIRS=	lib/pkgconfig

CMAKE_CONFIGURE_ARGS+=	-DBUILD_PLUGINS=none
CMAKE_CONFIGURE_ARGS+=	-DQT4_BUILD=ON
CMAKE_CONFIGURE_ARGS+=	-DQCA_MAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR} 

PKGCONFIG_OVERRIDE=		lib/pkgconfig/qca2.pc 
PKGCONFIG_OVERRIDE_STAGE=	post-configure

post-install:
	${INSTALL_DATA} ${DESTDIR}${QTDIR}/lib/pkgconfig/qca2.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/qca2.pc

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
