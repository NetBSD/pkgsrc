# $NetBSD: Makefile,v 1.39 2006/01/29 22:02:45 wiz Exp $
#

DISTNAME=		aspell-0.60.4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support

CONFLICTS=		libpspell-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
# for bin/aspell-import
USE_TOOLS+=		perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

INFO_FILES=		aspell-dev.info aspell.info

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses
CONFIGURE_ARGS+=	--enable-pkgdatadir=${PREFIX}/share/aspell
CONFIGURE_ARGS+=	--enable-dict-dir=${PREFIX}/lib/aspell

# Loadable filter currently don't work on NetBSD, see
# https://sourceforge.net/tracker/?func=detail&atid=100245&aid=1336865&group_id=245
# Disable dynamic loading of filters until it is fixed.
PKG_OPTIONS_VAR=	PKG_OPTIONS.aspell
#PKG_SUPPORTED_OPTIONS=	aspell-loadable-filters

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maspell-loadable-filters)
CONFIGURE_ARGS+=	--disable-compile-in-filters
PLIST_SUBST+=		FILTER=""
.else
CONFIGURE_ARGS+=	--enable-compile-in-filters
PLIST_SUBST+=		FILTER="@comment "
.endif

REPLACE_PERL=		scripts/aspell-import

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-build
SUBST_MESSAGE.bash=	bash is not really necessary, use sh.
SUBST_FILES.bash=	scripts/precat scripts/preunzip scripts/prezip
SUBST_SED.bash=		"s!/bin/bash!/bin/sh!"

NOT_FOR_COMPILER=	xlc

LIBS.SunOS+=		-lm

# Create directory for dictionaries.
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/aspell

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
