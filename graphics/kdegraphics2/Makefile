# $NetBSD: Makefile,v 1.4 2001/10/15 22:45:57 skrll Exp $
#

DISTNAME=	kdegraphics-2.2.1
CATEGORIES=	graphics kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	Graphics programs for the KDE integrated X11 desktop

DEPENDS+=	kdebase>=2.2.1:../../x11/kdebase2
DEPENDS+=	ghostscript>=6.01:../../print/ghostscript
#DEPENDS+=	gPhoto2
#DEPENDS+=	gpio

LTCONFIG_OVERRIDE+=	${WRKSRC}/kdvi/kpathsea/ltconfig

.include "../../x11/kde2/Makefile.part2"

LIBS=		-Wl,--export-dynamic

.include "../../mk/bsd.pkg.mk"
