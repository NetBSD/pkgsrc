# $NetBSD: Makefile,v 1.6 2001/11/10 19:43:33 skrll Exp $
#

DISTNAME=	kdeutils-2.2.1
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	misc kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Utilities for the KDE integrated X11 desktop

DEPENDS+=	kdebase>=2.2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

LIBS=		-Wl,--export-dynamic

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD") && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=	-D__NetBSD_APM__
.endif

post-install:
	${CHMOD} -s ${PREFIX}/bin/efax

.include "../../mk/bsd.pkg.mk"
