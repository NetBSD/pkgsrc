# $NetBSD: Makefile,v 1.3 2004/10/17 15:32:57 tv Exp $
#

.include "../../lang/kaffe/Makefile.common"

PKGNAME=		${DISTNAME:S/kaffe/kaffe-esound/}
PKGREVISION=		1

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
