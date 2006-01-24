# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:18 wiz Exp $

.include "../../lang/classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
PKGREVISION=	1
COMMENT+=	(GUI libraries)

DEPENDS+=	classpath>=0.12:../../lang/classpath

USE_TOOLS+=	pkg-config

BUILD_DIRS=	${WRKSRC}/native/jni/classpath
BUILD_DIRS+=	${WRKSRC}/native/jni/gtk-peer
INSTALL_DIRS=	${WRKSRC}/native/jni/gtk-peer

BUILDLINK_FILES.libart2+=	bin/libart2-config
BUILDLINK_TRANSFORM.libart2+=	-e 's|/libart2-config|/libart-config|g'

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
