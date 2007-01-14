# $NetBSD: Makefile,v 1.14 2007/01/14 09:22:02 joerg Exp $

.include "../../lang/classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
COMMENT+=	(GUI libraries)

DEPENDS+=	classpath>=0.93:../../lang/classpath

USE_TOOLS+=	pkg-config

BUILD_DIRS=	native/jni/classpath
BUILD_DIRS+=	native/jni/gtk-peer
INSTALL_DIRS=	native/jni/gtk-peer

BUILDLINK_FILES.libart2+=	bin/libart2-config
BUILDLINK_TRANSFORM.libart2+=	-e 's|/libart2-config|/libart-config|g'

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
