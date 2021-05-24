# $NetBSD: Makefile,v 1.7 2021/05/24 19:52:54 wiz Exp $

PKGREVISION= 2
.include "../../mail/libytnef/Makefile.common"

COMMENT=	Programs using libytnef to parse and handle TNEF attachments

USE_TOOLS+=	perl:run
BUILD_DIRS=	ytnef ytnefprint

REPLACE_PERL=	ytnef/ytnefprocess

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-build
SUBST_MESSAGE.prefix=	Setting prefix to ytnef in ytnefprocess
SUBST_FILES.prefix=	ytnef/ytnefprocess
SUBST_SED.prefix=	-e '/^my\ $$reader/s,/usr,${PREFIX},'

.include "../../mail/libytnef/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
