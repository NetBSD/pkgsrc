# $NetBSD: Makefile,v 1.20 2004/10/03 00:18:16 tv Exp $
#

DISTNAME=	vcdimager-0.7.20
PKGREVISION=	2
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
