# $NetBSD: Makefile,v 1.50 2020/03/20 11:57:36 nia Exp $
#

DISTNAME=	gpsim-20050905
PKGREVISION=	37
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://gpsim.sourceforge.net/
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++03

USE_TOOLS+=	bison gmake lex pkg-config
USE_LIBTOOL=	YES

GCC_REQD+=		3.0

CONFLICTS=	eXdbm-[0-9]* gpsim-[0-9]*

.include "../../devel/popt/buildlink3.mk"
# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
