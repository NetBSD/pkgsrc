# $NetBSD: Makefile,v 1.24 2021/08/28 09:22:23 nia Exp $

DISTNAME=	xfm-1.4.3
PKGREVISION=	7
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

PATCHFILES=		xfm-jumbo-patch-20181125.gz
PATCH_SITES=		http://www.NetBSD.org/~dholland/patchkits/xfm/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager
LICENSE=	gnu-gpl-v2

BUILD_TARGET+=	all xfm.install.script Xfm.ad

USE_IMAKE=	YES
IMAKEOPTS=	-DCppCmd=tradcpp
# does not directly support Xaw3d
.PHONY: buildlink-Xaw3d-inc-hack
pre-configure: buildlink-Xaw3d-inc-hack

buildlink-Xaw3d-inc-hack: buildlink-directories
	cd ${BUILDLINK_DIR}/include/X11 && ln -s Xaw3d Xaw
#BUILDLINK_TRANSFORM+=           l:Xaw:Xaw3d

TOOL_DEPENDS+=	tradcpp>=0.5.2:../../devel/tradcpp

.include "../../mk/bsd.prefs.mk"

.if empty(X11BASE:M${PREFIX})
CONF_FILES+=	${PREFIX}/lib/X11/app-defaults/Xfm \
		${X11BASE}/lib/X11/app-defaults/Xfm
.endif

.include "../../x11/libXaw3d/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
