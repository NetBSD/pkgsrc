# $NetBSD: Makefile,v 1.1.1.1 2004/06/10 13:15:03 hamajima Exp $
#

DISTNAME=	sqcam_driver_for_kernel_2_6
PKGNAME=	sq905view-0.01
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sqcam/}
EXTRACT_SUFX=	-0.1b.tar.gz

PATCH_SITES=	http://www2.starcat.ne.jp/~takam/bsd/
PATCHFILES= 	sqcam_driver_for_BSD-0.01.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	hamajima@NetBSD.org
HOMEPAGE=	http://www2.starcat.ne.jp/~takam/bsd/NetBSD.html#sqcam
COMMENT=	USB SQcam Webcam based the SQ905 chip Utility Programs

USE_BUILDLINK3=		yes

.include "../../graphics/imlib/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
