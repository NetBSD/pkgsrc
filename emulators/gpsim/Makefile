# $NetBSD: Makefile,v 1.11 2004/04/26 21:50:24 bouyer Exp $
#

DISTNAME=	gpsim-0.21.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.dattalo.com/gnupic/

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim.html
COMMENT=	PIC emulator with X interface

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-exdbm=${BUILDLINK_PREFIX.eXdbm}

USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES

USE_GNU_READLINE=	# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install

CONFLICTS=	eXdbm-[0-9]*

.include "../../devel/popt/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk+extra/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
