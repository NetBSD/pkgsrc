# $NetBSD: Makefile,v 1.33 2005/06/28 14:17:49 wiz Exp $
#

DISTNAME=		aspell-0.60.3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support

CONFLICTS=		libpspell-[0-9]*

USE_PERL5=		run # for bin/aspell-import
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

INFO_FILES=		aspell-dev.info aspell.info

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses
CONFIGURE_ARGS+=	--enable-pkgdatadir=${PREFIX}/share/aspell
CONFIGURE_ARGS+=	--enable-dict-dir=${PREFIX}/lib/aspell

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
