# $NetBSD: Makefile,v 1.13 2023/11/15 18:14:45 wiz Exp $

DISTNAME=	qtgrpc-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtgrpc-${QTVERSION}
PKGREVISION=	5
COMMENT=	Qt6 gRPC and Protobuf module
CATEGORIES=	net
LICENSE=	gnu-gpl-v3

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Grpc.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Protobuf.pc

.include "../../devel/protobuf/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../net/grpc/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
