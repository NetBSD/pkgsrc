# $NetBSD: Makefile,v 1.7 2003/11/12 01:31:49 salo Exp $
#

DISTNAME=	gpsim-0.20.7
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://www.dattalo.com/gnupic/

MAINTAINER=	snoonan@tbearsiberians.com
HOMEPAGE=	http://www.dattalo.com/gnupic/gpsim
COMMENT=	PIC emulator with X interface

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-exdbm=${BUILDLINK_PREFIX.eXdbm}

USE_GMAKE=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_GNU_READLINE=	# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install

.include "../../devel/eXdbm/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gtk+extra/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
