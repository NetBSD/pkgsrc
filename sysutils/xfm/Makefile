# $NetBSD: Makefile,v 1.19 2015/10/14 20:17:28 wiz Exp $

DISTNAME=	xfm-1.4.3
PKGREVISION=	4
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager
LICENSE=	gnu-gpl-v2

BUILD_TARGET+=	all xfm.install.script Xfm.ad

USE_IMAKE=	YES
# does not directly support Xaw3d
.PHONY: buildlink-Xaw3d-inc-hack
pre-configure: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	cd ${BUILDLINK_DIR}/include/X11 && ln -s Xaw3d Xaw
#BUILDLINK_TRANSFORM+=           l:Xaw:Xaw3d

.include "../../x11/libXaw3d/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
