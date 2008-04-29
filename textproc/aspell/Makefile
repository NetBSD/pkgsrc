# $NetBSD: Makefile,v 1.56 2008/04/29 11:40:50 wiz Exp $
#

DISTNAME=		aspell-0.60.6
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		libpspell-[0-9]*

GNU_CONFIGURE=		yes
USE_FEATURES=		snprintf vsnprintf
USE_TOOLS+=		gmake
# for bin/aspell-import
USE_TOOLS+=		perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses
CONFIGURE_ARGS+=	--enable-pkgdatadir=${PREFIX}/share/aspell
CONFIGURE_ARGS+=	--enable-dict-dir=${PREFIX}/lib/aspell
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CPPFLAGS+=	-DDECLARE_VSNPRINTF -DDECLARE_SNPRINTF
# IRIX 5 has an older implementation of signal()
CPPFLAGS+=	-DHAVE_OLD_SIGNAL
.endif

.include "options.mk"

REPLACE_PERL=		scripts/aspell-import

NOT_FOR_COMPILER=	xlc

LIBS.SunOS+=		-lm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
