# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 20:51:50 bouyer Exp $
#

DISTNAME=	gpsim-20040826
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim.html
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++

USE_GNU_TOOLS+=	make lex yacc
USE_LIBTOOL=	YES

USE_GNU_READLINE=	# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install

CONFLICTS=	eXdbm-[0-9]* gpsim-[0-9]*

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtk+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
