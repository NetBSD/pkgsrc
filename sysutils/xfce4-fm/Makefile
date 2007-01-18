# $NetBSD: Makefile,v 1.19 2007/01/18 15:20:45 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xffm-${XFCE4_VERSION}
PKGNAME=	xfce4-fm-${XFCE4_VERSION}
PKGREVISION=	4
CATEGORIES=	sysutils
COMMENT=	Xfce filemanager

MESSAGE_SRC+=	${.CURDIR}/MESSAGE

PKGCONFIG_OVERRIDE=	src/xffm-1.0.pc.in

CFLAGS+=		${PTHREAD_CFLAGS}
LIBS+=			${PTHREAD_LDFLAGS}

UNLIMIT_RESOURCES+=	datasize

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../databases/dbh/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
