# $NetBSD: Makefile,v 1.20 2004/02/14 17:21:53 jlam Exp $
#

DISTNAME=		aspell-0.50.4.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support

CONFLICTS=		libpspell-[0-9]*

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses

REPLACE_PERL=		scripts/aspell-import

# Create directory for dictionaries.
#
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/aspell

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
