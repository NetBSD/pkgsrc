# $NetBSD: Makefile,v 1.2 2001/04/06 17:56:03 tron Exp $

DISTNAME=	kdemultimedia-2.1
CATEGORIES=	audio kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	KDE audio tools

DEPENDS+=	kdebase-2.1:../../x11/kdebase2
DEPENDS+=	pth>=1.3.7:../../devel/pth

.include "../../x11/kde2/Makefile.part2"

CONFIGURE_ENV+=	LIBS="-Wl,--export-dynamic"

.include "../../mk/bsd.pkg.mk"
