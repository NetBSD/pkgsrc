# $NetBSD: Makefile,v 1.4 2003/12/13 00:45:25 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xffm-${XFCE4_VERSION}
PKGNAME=	xfce4-fm-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	sysutils
COMMENT=	XFce4 filemanager

MESSAGE_SRC+=	${.CURDIR}/MESSAGE

PKGCONFIG_OVERRIDE=	src/xffm-1.0.pc.in

UNLIMIT_RESOURCES+=     datasize

.include "../../databases/dbh/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
