# $NetBSD: Makefile,v 1.18 2004/04/19 17:58:25 drochner Exp $
#

DISTNAME=	vcdimager-0.7.20
PKGREVISION=	1
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
.include "../../devel/popt/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
