# $NetBSD: Makefile,v 1.56 2022/07/02 16:53:32 ryoon Exp $

DISTNAME=	krdc-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	net

HOMEPAGE=	https://kde.org/applications/internet/krdc/
COMMENT=	KDE remote desktop client
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../net/freerdp2/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/libvncserver/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../security/libssh/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
