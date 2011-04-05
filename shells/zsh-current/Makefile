# $NetBSD: Makefile,v 1.20 2011/04/05 13:54:24 ryoon Exp $

.include "../../shells/zsh/Makefile.common"

ZSH_VERSION=	4.3.11
ZSH_MAINTAINER=	ryoon@NetBSD.org

USE_TOOLS+=	env

SUBST_CLASSES+=	prefix-fixup
SUBST_STAGE.prefix-fixup=	pre-configure
SUBST_FILES.prefix-fixup= \
	Misc/globtests \
	Misc/globtests.ksh \
	Test/ztst.zsh \
	Util/reporter \
	Functions/Calendar/calendar_add \
	Functions/Misc/run-help \
	Functions/Misc/checkmail \
	Functions/Misc/sticky-note \
	Functions/Misc/zcalc \
	Functions/Misc/zkbd \
	Functions/Misc/zed \
	Functions/Example/cat
SUBST_SED.prefix-fixup= \
	-e 's|^\#\!/bin/env|\#\!${TOOLS_PATH.env}|g' \
	-e 's|^\#\! /bin/env|\#\! ${TOOLS_PATH.env}|g' \
	-e 's|^\#\!/bin/zsh|\#\!${PREFIX}/bin/zsh|g' \
	-e 's|^\#\! /bin/zsh|\#\! ${PREFIX}/bin/zsh|g' \
	-e 's|^\#\!/usr/local/bin/zsh|\#\!${PREFIX}/bin/zsh|g' \
	-e 's|^\#\! /usr/local/bin/zsh|\#\! ${PREFIX}/bin/zsh|g'

.include "../../mk/bsd.pkg.mk"
