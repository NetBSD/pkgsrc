# $NetBSD: Makefile,v 1.2 2002/04/09 21:48:25 frueauf Exp $

DISTNAME=		ettercap-0.6.4
CATEGORIES=		security net
MASTER_SITES=		http://ettercap.sourceforge.net/download/

MAINTAINER=		nk@bsdirc.net
HOMEPAGE=		http://ettercap.sourceforge.net/
COMMENT=		Multipurpose sniffer/interceptor/logger for switched LAN

GNU_CONFIGURE=		yes

USE_CURSES=		yes
USE_PTHREAD=		native pth

CPPFLAGS+=		-I${LOCALBASE}/include -L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib

.include "../../devel/ncurses/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
