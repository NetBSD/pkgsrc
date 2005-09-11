# $NetBSD: Makefile,v 1.36 2005/09/11 16:29:58 minskim Exp $
#

DISTNAME=		aspell-0.60.3
PKGREVISION=		1
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

# configure fails to detect dlopen() on NetBSD.  Disable dynamic
# loading of filters until it is fixed.
CONFIGURE_ARGS+=	--enable-compile-in-filters

REPLACE_PERL=		scripts/aspell-import

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	post-build
SUBST_MESSAGE.bash=	bash is not really necessary, use sh.
SUBST_FILES.bash=	scripts/precat scripts/preunzip scripts/prezip
SUBST_SED.bash=		"s!/bin/bash!/bin/sh!"

NOT_FOR_COMPILER=	xlc

LIBS.SunOS+=		-lm

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
LIBS.SunOS+=		-lCrun -lCstd
.endif

# Create directory for dictionaries.
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/aspell

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
