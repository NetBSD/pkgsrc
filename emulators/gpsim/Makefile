# $NetBSD: Makefile,v 1.12 2004/04/26 22:34:17 snj Exp $
#

DISTNAME=	gpsim-0.21.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.dattalo.com/gnupic/

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim.html
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++

USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES

USE_GNU_READLINE=	# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install

CONFLICTS=	eXdbm-[0-9]*

.include "../../devel/popt/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gtk+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
