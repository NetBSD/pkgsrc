# $NetBSD: Makefile,v 1.28 2012/10/02 17:11:26 tron Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/sablevm-classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
PKGREVISION=	14
COMMENT+=	(GUI libraries)

DEPENDS+=	sablevm-classpath>=1.13nb1:../../lang/sablevm-classpath

USE_TOOLS+=	pkg-config

BUILD_DIRS=	native/jni/classpath
BUILD_DIRS+=	native/jni/gtk-peer
INSTALL_DIRS=	native/jni/gtk-peer

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
