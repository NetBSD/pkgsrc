# $NetBSD: Makefile,v 1.59 2023/11/12 13:21:21 wiz Exp $
#

DISTNAME=	gpsim-20050905
PKGREVISION=	44
CATEGORIES=	emulators
MASTER_SITES=	http://www-asim.lip6.fr/~bouyer/pic/

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://gpsim.sourceforge.net/
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
