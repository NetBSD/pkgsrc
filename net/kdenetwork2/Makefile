# $NetBSD: Makefile,v 1.5 2001/10/15 22:46:15 skrll Exp $
#

DISTNAME=	kdenetwork-2.2.1
CATEGORIES=	net kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Network modules for the KDE integrated X11 desktop

DEPENDS=	gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=	uulib>=0.5.13:../../converters/uulib
DEPENDS+=	ptl>=2.1.7:../../devel/ptl2
DEPENDS+=	kdebase>=2.2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
