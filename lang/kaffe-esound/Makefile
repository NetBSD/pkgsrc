# $NetBSD: Makefile,v 1.1 2004/07/04 15:24:46 jmmv Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=		${DISTNAME:S/kaffe/kaffe-esound/}

COMMENT+=		(sound support through esound)

CONFIGURE_ARGS:=	${CONFIGURE_ARGS:S/--without-esd/--with-esd/}

BUILD_DIRS=		${WRKSRC}/config
BUILD_DIRS+=		${WRKSRC}/include
BUILD_DIRS+=		${WRKSRC}/libraries/extensions/sound/esd
INSTALL_DIRS=		${WRKSRC}/libraries/extensions/sound/esd

PRINT_PLIST_AWK+=	/^@dirrm/ { print "@comment in kaffe: " $$0; next; }

.include "../../audio/esound/buildlink3.mk"
.include "../../lang/kaffe/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
