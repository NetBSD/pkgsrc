# $NetBSD: Makefile,v 1.2 2004/10/03 00:15:01 tv Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=		${DISTNAME:S/kaffe/kaffe-x11/}
PKGREVISION=	1

COMMENT+=		(AWT support through X11)

USE_X11=		YES

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--without-awt/--with-awt=X/}

BUILD_DIRS=		${WRKSRC}/config
BUILD_DIRS+=		${WRKSRC}/libraries/clib/awt
INSTALL_DIRS=		${WRKSRC}/libraries/clib/awt

PRINT_PLIST_AWK+=	/^@dirrm/ { print "@comment in kaffe: " $$0; next; }

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/kaffe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
