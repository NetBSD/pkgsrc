# $NetBSD: Makefile,v 1.5 2006/02/05 23:09:46 joerg Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=		${DISTNAME:S/kaffe/kaffe-esound/}
PKGREVISION=		1

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
