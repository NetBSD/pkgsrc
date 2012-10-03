# $NetBSD: Makefile,v 1.25.2.1 2012/10/03 12:07:37 spz Exp $
#

DISTNAME=	gpsim-20050905
PKGREVISION=	18
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://gpsim.sourceforge.net/
COMMENT=	PIC emulator with X interface

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_TOOLS+=	bison gmake lex pkg-config
USE_LIBTOOL=	YES

GCC_REQD+=		3.0

USE_GNU_READLINE=	YES
# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install

CONFLICTS=	eXdbm-[0-9]* gpsim-[0-9]*

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
