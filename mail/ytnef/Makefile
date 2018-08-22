# $NetBSD: Makefile,v 1.2 2018/08/22 09:45:35 wiz Exp $

PKGREVISION= 1
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
