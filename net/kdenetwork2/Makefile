# $NetBSD: Makefile,v 1.2 2001/03/24 18:33:55 skrll Exp $
#

DISTNAME=	kdenetwork-2.1
CATEGORIES=	net kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Network modules for the KDE integrated X11 desktop

DEPENDS=	gdbm>=1.7.3:../../databases/gdbm
DEPENDS+=	uulib-0.5.13:../../converters/uulib
DEPENDS+=	ptl>=2.1.7:../../devel/ptl2
DEPENDS+=	kdesupport-2.1:../../converters/kdesupport2
DEPENDS+=	kdebase-2.1:../../x11/kdebase2

.include "../../x11/kde2/Makefile.part2"

.include "../../mk/bsd.pkg.mk"
