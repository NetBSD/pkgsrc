# $NetBSD: Makefile,v 1.25 2004/10/07 16:36:47 tv Exp $
#

DISTNAME=		aspell-0.50.5
PKGREVISION=		3
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

LIBS.SunOS+=		-lm

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
LIBS.SunOS+=		-lCrun -lCstd
.endif

pre-patch:
.if !empty(PKGSRC_COMPILER:Msunpro)
	@cd ${WRKSRC} && ${PATCH} -p1 -s < suncc/aspell-0.50.4.1-suncc.diff
.endif

# Create directory for dictionaries.
#
post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/aspell

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
