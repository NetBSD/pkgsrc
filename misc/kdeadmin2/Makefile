# $NetBSD: Makefile,v 1.3 2001/10/15 22:46:15 skrll Exp $
#

DISTNAME=	kdeadmin-2.2.1
CATEGORIES=	misc kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Utilities for the KDE integrated X11 desktop

DEPENDS+=	kdebase>=2.2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ARGS+= "--without-shadow"

.include "../../mk/bsd.pkg.mk"
