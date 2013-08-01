# $NetBSD: Makefile,v 1.64 2013/08/01 06:08:33 wiz Exp $

.include "../../shells/zsh/Makefile.common"

PKGREVISION=	2

ZSH_VERSION=	5.0.2
ZSH_MAINTAINER=	uebayasi@NetBSD.org

CONFIGURE_ARGS+=	--disable-gdbm

SUBST_CLASSES+=	prefix-fixup
SUBST_STAGE.prefix-fixup=	pre-configure
SUBST_FILES.prefix-fixup= \
	Misc/globtests \
	Misc/globtests.ksh \
	Test/ztst.zsh \
	Test/runtests.zsh \
	Util/reporter \
	Functions/Calendar/calendar_add \
	Functions/Misc/run-help \
	Functions/Misc/checkmail \
	Functions/Misc/sticky-note \
	Functions/Misc/zcalc \
	Functions/Misc/zkbd \
	Functions/Misc/zed \
	Functions/Example/cat \
	Functions/Example/zless
SUBST_SED.prefix-fixup= 	-e 's|^\#\!/bin/zsh|\#\!${PREFIX}/bin/zsh|g'
SUBST_SED.prefix-fixup+=	-e 's|^\#\! /bin/zsh|\#\! ${PREFIX}/bin/zsh|g'
SUBST_SED.prefix-fixup+=	-e 's|^\#\!/usr/local/bin/zsh|\#\!${PREFIX}/bin/zsh|g'
SUBST_SED.prefix-fixup+=	-e 's|^\#\! /usr/local/bin/zsh|\#\! ${PREFIX}/bin/zsh|g'

.include "../../mk/bsd.pkg.mk"
