# $NetBSD: Makefile,v 1.3 2003/12/04 19:48:26 xtraeme Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

PKGNAME=	xfce4-fm-${XFCE4_VERSION}
DISTNAME=	xffm-${XFCE4_VERSION}
PKGREVISION=	1
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
