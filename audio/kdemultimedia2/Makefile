# $NetBSD: Makefile,v 1.5 2001/09/07 14:27:10 drochner Exp $

DISTNAME=	kdemultimedia-2.1
CATEGORIES=	audio kde
.include "../../x11/kde2/Makefile.part1"
COMMENT=	KDE audio tools

DEPENDS+=	kdebase>=2.1:../../x11/kdebase2
DEPENDS+=	pth>=1.3.7:../../devel/pth

.include "../../x11/kde2/Makefile.part2"

LIBS=		-Wl,--export-dynamic

post-patch:
	${CP} ${WRKSRC}/kscd/config.h.std ${WRKSRC}/kscd/config.h

.include "../../mk/bsd.pkg.mk"
