# $NetBSD Exp $

DISTNAME=		ettercap-0.6.4
CATEGORIES=		security net
MASTER_SITES=		http://ettercap.sourceforge.net/download/

MAINTAINER=		nk@bsdirc.net
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes

USE_CURSES=		yes

WRKSRC=			${WRKDIR}/${DISTNAME}
CPPFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib

.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
