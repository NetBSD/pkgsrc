# $NetBSD: Makefile,v 1.1.1.1 2008/09/08 10:31:23 shannonjr Exp $
#

DISTNAME=	osbf-lua-2.0.4
CATEGORIES=	local
MASTER_SITES=	http://luaforge.net/frs/download.php/2094/

MAINTAINER=	shannonjr@NetBSD.org
HOMEPAGE=	http://osbf-lua.luaforge.net/
COMMENT=	Lua C module for text classification

USE_TOOLS+=		gmake

INSTALL_TARGET=	install install_spamfilter

SUBST_CLASSES+=         path
SUBST_STAGE.path=       post-patch
SUBST_MESSAGE.path=     Fixing paths in config
SUBST_FILES.path=       config
SUBST_FILES.path+=      spamfilter/cache_report.lua
SUBST_FILES.path+=      spamfilter/classify.sample
SUBST_FILES.path+=      spamfilter/create_databases.lua
SUBST_FILES.path+=      spamfilter/database_status.lua
SUBST_FILES.path+=      spamfilter/getopt.lua
SUBST_FILES.path+=      spamfilter/promailrc.sample
SUBST_FILES.path+=      spamfilter/random.lua
SUBST_FILES.path+=      spamfilter/roc.lua
SUBST_FILES.path+=      spamfilter/spamfilter.lua
SUBST_FILES.path+=      spamfilter/spamfilter_commands.lua
SUBST_FILES.path+=      spamfilter/toer.lua
SUBST_FILES.path+=      spamfilter/train.sample
SUBST_FILES.path+=      docs/index.html
SUBST_SED.path=         -e 's,/usr/local,${PREFIX},g'

.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
