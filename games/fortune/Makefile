# $NetBSD: Makefile,v 1.2 2020/01/26 17:31:14 rillig Exp $

DISTNAME=	fortune-mod-9708
PKGNAME=	fortune-19970829
CATEGORIES=	games
MASTER_SITES=	http://www.ibiblio.org/pub/linux/games/amusements/fortune/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.ibiblio.org/pub/linux/games/amusements/fortune/
COMMENT=	Fortune cookie generator
LICENSE=	original-bsd

DEPENDS+=	fortune-strfile>=0:../../games/fortune-strfile

.include "options.mk"

BUILD_TARGET=	fortune-bin cookies-z
MAKE_ENV+=	STRFILE=${PREFIX}/bin/strfile

PRINT_PLIST_AWK+=	/fortune\/off\// { $$0 = "$${PLIST.off}" $$0; }

.include "../../mk/bsd.pkg.mk"
