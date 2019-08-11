# $NetBSD: Makefile,v 1.3 2019/08/11 13:21:43 wiz Exp $

PKGREVISION= 2
.include "../../mail/libytnef/Makefile.common"

USE_TOOLS+=		perl:run
BUILD_DIRS=		ytnef ytnefprint

REPLACE_PERL=           ytnef/ytnefprocess

SUBST_CLASSES+=         prefix
SUBST_STAGE.prefix=     pre-build
SUBST_MESSAGE.prefix=   Setting prefix to ytnef in ytnefprocess
SUBST_FILES.prefix=     ytnef/ytnefprocess
SUBST_SED.prefix=       -e '/^my\ $$reader/s,/usr,${PREFIX},'

.include "../../mail/libytnef/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
