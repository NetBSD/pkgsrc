# $NetBSD: Makefile,v 1.13 2005/11/09 07:09:04 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xffm-${XFCE4_VERSION}
PKGNAME=	xfce4-fm-${XFCE4_VERSION}
CATEGORIES=	sysutils
COMMENT=	Xfce filemanager

MESSAGE_SRC+=	${.CURDIR}/MESSAGE

PKGCONFIG_OVERRIDE=	src/xffm-1.0.pc.in

CFLAGS+=		${PTHREAD_CFLAGS}
LIBS+=			${PTHREAD_LDFLAGS}

UNLIMIT_RESOURCES+=     datasize

.include "../../databases/dbh/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
