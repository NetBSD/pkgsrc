# $NetBSD: Makefile,v 1.13 2003/09/27 17:07:38 grant Exp $
#

DISTNAME=		aspell-0.50.3
PKGREVISION=		3
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

# halfdelay()
INCOMPAT_CURSES=	NetBSD-1.[45]*-* NetBSD-1.6[-_.]* NetBSD-1.6[A-L]-*

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses

REPLACE_PERL=		scripts/aspell-import

# Create directory for dictionaries.
#
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/aspell

.include "../../mk/curses.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
