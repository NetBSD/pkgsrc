# $NetBSD: Makefile,v 1.5 2005/07/21 16:29:52 wiz Exp $
#

.include "../../lang/sablevm-classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
PKGREVISION=	2
COMMENT+=	(GUI libraries)

DEPENDS+=	sablevm-classpath>=1.1.3nb1:../../lang/sablevm-classpath

BUILD_DIRS=	${WRKSRC}/native/jni/classpath
BUILD_DIRS+=	${WRKSRC}/native/jni/gtk-peer
INSTALL_DIRS=	${WRKSRC}/native/jni/gtk-peer

PRINT_PLIST_AWK+= \
	/^@dirrm java\/sablevm\/lib\/sablevm\/sablevm-classpath$$/ \
		{ print "@comment in sablevm-classpath: "$$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
