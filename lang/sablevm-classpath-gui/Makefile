# $NetBSD: Makefile,v 1.11 2006/04/17 12:21:14 tonio Exp $
#

.include "../../lang/sablevm-classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
COMMENT+=	(GUI libraries)

DEPENDS+=	sablevm-classpath>=1.13nb1:../../lang/sablevm-classpath

USE_TOOLS+=	pkg-config

BUILD_DIRS=	native/jni/classpath
BUILD_DIRS+=	native/jni/gtk-peer
INSTALL_DIRS=	native/jni/gtk-peer

PRINT_PLIST_AWK+= \
	/^@dirrm java\/sablevm\/lib\/sablevm-classpath$$/ \
		{ print "@comment in sablevm-classpath: "$$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
