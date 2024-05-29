# $NetBSD: Makefile,v 1.13 2024/05/29 16:34:21 adam Exp $

DISTNAME=	yubikey-manager-qt-1.2.5
PKGREVISION=	9
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/yubikey-manager-qt/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubikey-manager-qt/
COMMENT=	Cross-platform GUI for configuring any YubiKey over all USB interfaces
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-otherside-[0-9]*:../../x11/py-otherside
DEPENDS+=	${PYPKGPREFIX}-yubikey-manager-[0-9]*:../../security/py-yubikey-manager
DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects
DEPENDS+=	qt5-qtquickcontrols-[0-9]*:../../x11/qt5-qtquickcontrols

WRKSRC=		${WRKDIR}/yubikey-manager-qt
USE_LANGUAGES=	c++

MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}
# https://github.com/Yubico/yubikey-manager-qt/issues/342
MAKE_ENV+=		SUBLIBS=-lpython${PYVERSSUFFIX}
INSTALLATION_DIRS+=	bin

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

pre-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTDIR}/bin/qmake

post-install:
	${MV} ${DESTDIR}/usr/bin/* ${DESTDIR}${PREFIX}/bin

.include "../../security/libyubikey/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
