# $NetBSD: Makefile,v 1.28 2012/09/15 10:05:18 obache Exp $

.include "../../lang/classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
PKGREVISION=	13
COMMENT+=	(GUI libraries)

DEPENDS+=	classpath>=0.93:../../lang/classpath

USE_TOOLS+=	pkg-config

BUILD_DIRS=	native/jni/classpath
BUILD_DIRS+=	native/jni/gtk-peer
INSTALL_DIRS=	native/jni/gtk-peer

BUILDLINK_FILES.libart+=	bin/libart2-config
BUILDLINK_FNAME_TRANSFORM.libart+=	-e 's|/libart2-config|/libart-config|g'

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
