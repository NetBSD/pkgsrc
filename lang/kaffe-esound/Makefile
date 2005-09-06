# $NetBSD: Makefile,v 1.4 2005/09/06 18:18:54 tonio Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=		${DISTNAME:S/kaffe/kaffe-esound/}

COMMENT+=		(sound support through esound)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--without-esd/--with-esd/}
CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--disable-esdtest//}

BUILD_DIRS=		  ${WRKSRC}/config
BUILD_DIRS+=    ${WRKSRC}/libraries/javalib
BUILD_DIRS+=		${WRKSRC}/include
BUILD_DIRS+=		${WRKSRC}/libraries/clib/sound/esd
INSTALL_DIRS=		${WRKSRC}/libraries/clib/sound/esd

PRINT_PLIST_AWK+=	/^@dirrm/ { print "@comment in kaffe: " $$0; next; }

.include "../../audio/esound/buildlink3.mk"
.include "../../lang/kaffe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
