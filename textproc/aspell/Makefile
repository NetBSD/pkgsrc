# $NetBSD: Makefile,v 1.81 2024/05/06 08:33:53 jperkin Exp $

DISTNAME=		aspell-0.60.8.1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU:=aspell/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://aspell.net/
COMMENT=		Spell checker with good multi-language support
LICENSE=		gnu-lgpl-v2.1

CONFLICTS=		libpspell-[0-9]*

GNU_CONFIGURE=		yes
USE_FEATURES=		snprintf vsnprintf
USE_TOOLS+=		gmake
USE_TOOLS+=		msgfmt msgmerge xgettext
# for bin/aspell-import
USE_TOOLS+=		perl:run
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
INFO_FILES=		yes

CONFIGURE_ARGS+=	--enable-curses=${CURSES_TYPE}
CONFIGURE_ARGS+=	--enable-pkgdatadir=${PREFIX}/share/aspell
CONFIGURE_ARGS+=	--enable-dict-dir=${PREFIX}/lib/aspell
# https://github.com/GNUAspell/aspell/issues/336
CONFIGURE_ARGS+=	--enable-compile-in-filters
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes

.include "../../mk/bsd.prefs.mk"

# aspell does not work with curses in NetBSD <= 8.0.
.if ${MACHINE_PLATFORM:MNetBSD-8.0.*} || \
    ${MACHINE_PLATFORM:MNetBSD-[0-7].*}
USE_CURSES=	ncurses
.endif

.if ${MACHINE_PLATFORM:MIRIX-5.*}
CPPFLAGS+=	-DDECLARE_VSNPRINTF -DDECLARE_SNPRINTF
# IRIX 5 has an older implementation of signal()
CPPFLAGS+=	-DHAVE_OLD_SIGNAL
.endif

REPLACE_PERL=		scripts/aspell-import

NOT_FOR_COMPILER=	xlc

LIBS.SunOS+=		-lm

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
