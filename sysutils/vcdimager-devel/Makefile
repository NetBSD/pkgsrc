# $NetBSD: Makefile,v 1.22 2005/01/21 21:16:33 wiz Exp $
#

DISTNAME=	vcdimager-0.7.20
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.vcdimager.org/pub/vcdimager/vcdimager-0.7_UNSTABLE/

MAINTAINER=	ben@NetBSD.org
HOMEPAGE=	http://www.vcdimager.org/
COMMENT=	Mastering suite for Video CDs

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	YES
USE_LIBTOOL=	yes
INFO_FILES=	vcd-info.info vcdimager.info vcdxrip.info
PKGCONFIG_OVERRIDE+= libvcdinfo.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+= rm:-Wl,--version-script=libvcdinfo.la.ver
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
