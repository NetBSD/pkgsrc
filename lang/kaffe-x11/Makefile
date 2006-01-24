# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:18 wiz Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=    ${DISTNAME:S/kaffe/kaffe-x11/}
PKGREVISION=	1

COMMENT+=   (AWT support through X11)

CONFIGURE_ARGS:=  ${CONFIGURE_ARGS:S/--disable-native-awt/--with-kaffe-x-awt/}

BUILD_DIRS=     ${WRKSRC}/config
BUILD_DIRS+=    ${WRKSRC}/libraries/javalib
BUILD_DIRS+=    ${WRKSRC}/include
BUILD_DIRS+=    ${WRKSRC}/replace
BUILD_DIRS+=    ${WRKSRC}/kaffe/kaffevm
BUILD_DIRS+=    ${WRKSRC}/libraries/clib/classpath
BUILD_DIRS+=    ${WRKSRC}/libraries/clib/awt
INSTALL_DIRS=   ${WRKSRC}/libraries/clib/awt

PRINT_PLIST_AWK+= /^@dirrm/ { print "@comment in kaffe: " $$0; next; }

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/kaffe/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
