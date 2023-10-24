# $NetBSD: Makefile,v 1.47 2023/10/24 22:10:57 wiz Exp $

PKGNAME=	qca2-${DISTNAME:C/.*-//}
PKGREVISION=	6

COMMENT=	Cross-platform crypto API for QT

.include "Makefile.common"

DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts

INSTALLATION_DIRS=	lib/pkgconfig

CMAKE_ARGS+=	-DBUILD_PLUGINS=none
CMAKE_ARGS+=	-DQT4_BUILD=ON
CMAKE_ARGS+=	-DQCA_MAN_INSTALL_DIR=${PREFIX}/${PKGMANDIR} 

PKGCONFIG_OVERRIDE=		lib/pkgconfig/qca2.pc 
PKGCONFIG_OVERRIDE_STAGE=	post-configure

post-install:
	${INSTALL_DATA} ${DESTDIR}${QTDIR}/lib/pkgconfig/qca2.pc ${DESTDIR}${PREFIX}/lib/pkgconfig/qca2.pc

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
