# $NetBSD: Makefile,v 1.16 2003/12/03 16:49:06 recht Exp $
#

DISTNAME=		aspell-0.50.4.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support

CONFLICTS=		libpspell-[0-9]*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GCC_SHLIB=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses

REPLACE_PERL=		scripts/aspell-import

# Create directory for dictionaries.
#
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/aspell

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
