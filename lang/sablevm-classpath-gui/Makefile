# $NetBSD: Makefile,v 1.2 2004/04/30 21:12:55 jmmv Exp $
#

.include "../../lang/sablevm-classpath/Makefile.common"

PKGNAME=	${DISTNAME:S/classpath/classpath-gui/}
COMMENT+=	(GUI libraries)

DEPENDS+=	sablevm-classpath>=1.1.3:../../lang/sablevm-classpath

BUILD_DIRS=	${WRKSRC}/native/jni/classpath
BUILD_DIRS+=	${WRKSRC}/native/jni/gtk-peer
INSTALL_DIRS=	${WRKSRC}/native/jni/gtk-peer

PRINT_PLIST_AWK+=	/^@dirrm lib\/sablevm\/sablevm-classpath$$/ \
				{ print "@comment in sablevm-classpath: "$$0; \
				  next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
