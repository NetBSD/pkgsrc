# $NetBSD: Makefile,v 1.6 2001/10/15 22:45:55 skrll Exp $

DISTNAME=	kdemultimedia-2.2.1
CATEGORIES=	audio kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	KDE audio tools

DEPENDS+=	kdebase>=2.2.1:../../x11/kdebase2
DEPENDS+=	pth>=1.4.0:../../devel/pth

.include "../../x11/kde2/Makefile.part2"

LIBS=		-Wl,--export-dynamic

.include "../../mk/bsd.pkg.mk"
