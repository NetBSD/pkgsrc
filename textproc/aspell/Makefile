# $NetBSD: Makefile,v 1.47 2006/11/24 16:31:48 rillig Exp $
#

DISTNAME=		aspell-0.60.4
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		libpspell-[0-9]*

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
# for bin/aspell-import
USE_TOOLS+=		perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--enable-doc-dir=${PREFIX}/share/doc/aspell
CONFIGURE_ARGS+=	--enable-curses=ncurses
CONFIGURE_ARGS+=	--enable-pkgdatadir=${PREFIX}/share/aspell
CONFIGURE_ARGS+=	--enable-dict-dir=${PREFIX}/lib/aspell
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes

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

NOT_FOR_COMPILER=	xlc

LIBS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"
.if !empty(LOWER_OPSYS:Mirix5*)
# needs vsnprintf() and snprintf()
. include "../../pkgtools/libnbcompat/buildlink3.mk"
CPPFLAGS+=	-DDECLARE_VSNPRINTF -DDECLARE_SNPRINTF
# IRIX 5 has an older implementation of signal()
CPPFLAGS+=	-DHAVE_OLD_SIGNAL
.endif
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
