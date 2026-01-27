# $NetBSD: Makefile,v 1.70 2026/01/27 08:39:24 wiz Exp $
#

DISTNAME=	gpsim-20050905
PKGREVISION=	53
CATEGORIES=	emulators
MASTER_SITES=	https://largo.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://gpsim.sourceforge.net/
COMMENT=	PIC emulator with X interface

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

USE_TOOLS+=	bison gmake lex pkg-config
USE_LIBTOOL=	YES

CONFLICTS=	eXdbm-[0-9]* gpsim-[0-9]*

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../devel/popt/buildlink3.mk"
# rl_callback_read_char, rl_copy_text,
# rl_callback_handler_remove, rl_forced_update_display,
# rl_callback_handler_install
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk2+extra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
